#include "rtweekend.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdlib.h>//just to clear console screan.(system("cls")) and rand()
using namespace std;

color ray_color(const ray &r, const hittable &world)
{
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec))
    {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

bool not_in_array(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return false; // It's in the array
    }
    return true; // It's not in the array
}


int main()
{
    
    system("cls");
    srand(time(0));//seeding rand
    // Image
    string fname="output.ppm";
    int image_width = 400;
    int image_height = 400;
    int n;
    cout<<"Enter number of spheres(1 -10) :";
    cin>>n;
    while(!(n>=1) && (n<=10)){
        cout<<"Enter n between 1 and 10";
        cout<<"Enter number of spheres(1 -10) :";
        cin>>n;
    }
    float r[n];
    for(int i=0;i<n;i++){
        cout<<"Enter R"<<i+1<<" :";
        cin>>r[i];
    }
    
    //menu

    cout<<R"(Options :
-- 1)spheres N                Number of spheres to render (1 -10)
-- 2)radius R1 , R2 ,...      Comma - separated list of sphere radii
-- 3)output FILENAME          Output PPM filename ( default : output . ppm )
-- 4)width W                  Image width in pixels ( default : 400)
-- 5)height H                 Image height in pixels ( default : 400)
-- 6)help                     Show usage information)";
    int ch;
    cout<<"\nEnter choice or enter 1 to continue the render :";
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"There are "<<n<<" spheres.";
            break;
        case 2:
            for(int i=0;i<n;i++){
                cout<<"R"<<i+1<<"-"<<r[i];
            }
            break;
        case 3:
            cout<<"Enter new filename with .ppm:";
            cin>>fname;
            break;
        case 4:
            cout<<"Enter new image_width :";
            cin>>image_width;
            break;
        case 5:
            cout<<"Enter new image_height :";
            cin>>image_height;
            break;
        case 6:
            cout<<R"(                         Welcome to Random Sphere Ray Tracer
							-Harikrishna S 240424
First Enter the number of spheres and the radius of each sphere.
A menu will be displayed, after which enter the number in front of the option to enter the choice.

1)spheres : It will display the number of spheres you have entered.
2)radius  : It will display all the radii in order.
3)output filename: In case you want to change the default filename.
4)width   : To change the image width in pixels
5)height  : To change the image height in pixels

                         Thank you!)";
            
            break;
        default:
            cout<<"Enter a valid choice :";
            break;
    }
    //ppm file
    ofstream ppmfile(fname);


    // World
    
    hittable_list world;
    
    //array of the coordinates of the centers
    vec3 centers[n];
    float rmax = *max_element(r, r + n);
    
    //finding all possible viable points.
    vec3 viable[7500];
    int countv=0;
    
    int spacing = max(2, int(rmax * 2));

    for(int i=5;i<=15;i++){
        for(int j=-2*i;j<=2*i;j+=spacing){
            for(int k=-2*i;k<=2*i;k+=spacing){
                viable[countv]=vec3(j,k,-i);
                countv++;
            }
        }
    }

    //Randomly choosing n points from them.
    int rindex[n];//Choosing random indices from viable.
    if (n > countv) {
        cerr << "Error: More spheres than available viable positions!" << endl;
        return 1;
    }


    fill_n(rindex, n, -1);

    for (int i = 0; i < n; i++) {
        while (true) {
            int y = rand() % countv;
            if (not_in_array(rindex, i, y)) {
                rindex[i] = y;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        centers[i]=viable[rindex[i]];
    }
    
    for(int i=0;i<n;i++){
        world.add(make_shared<sphere>(centers[i], r[i]));
    }
    
    //world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    // ground if required world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));




    // Camera
    auto focal_length = 1.0;
    auto aspect_ratio = double(image_width) / image_height;
    auto viewport_height = 4.0;
    auto viewport_width = viewport_height * aspect_ratio;

    auto camera_center = point3(0, 0, 0);
    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);
    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;
    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    if (!ppmfile) { cerr << "fail"; return 1; }//to check if file is open
    // Render
    ppmfile << "P3\n"<< image_width << ' ' << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++)
    {
        clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush;
        for (int i = 0; i < image_width; i++)
        {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + ((j)  * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);
            color pixel_color = ray_color(r, world);
            write_color(ppmfile, pixel_color);
        }
    }
    clog << "\rDone. \n";
    ppmfile.close();
}