#include <iostream>
#include <math.h>
#define ULL unsigned long long
using namespace std;

bool point_in_square(double x, double y, int xl, int yl, int xr, int yr){
    return ((xl <=x) & (x <= xr) & (yl <= y) & (y <= yr));
}

void getIntersection(int a1, int b1, int c1, int a2, int b2, int c2, bool &intersects, double &x, double &y){
    int delta = a1*b2-a2*b1;
    if (delta == 0){
        intersects = 0;
        return;
    }
    intersects = 1;
    int deltax = c2*b1-c1*b2;
    int deltay = a2*c1-a1*c2;
    // cout << "delta: " << delta << "\n";
    // cout << "deltax: " << deltax << "\n";
    // cout << "deltay: " << deltay << "\n";
    x = static_cast<double>(deltax)/static_cast<double>(delta);
    y = static_cast<double>(deltay)/static_cast<double>(delta);
}
bool point_in_segment(int x, int y, int x1, int y1, int x2, int y2){
    // cout << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")\n";
    // cout << "(" << x << ", " << y << "): ";
    if (x1 < x2){
        if (!((x1 <= x) && (x <= x2))){
            // cout << "false\n";
            return false;
        }
    }
    else{
        if (!((x2 <= x) && (x <= x1))){
            // cout << "false\n";
            return false;
        }
    }

    if (y1 < y2){
        if (!((y1 <= y) && (y <= y2))){
            // cout << "false\n";
            return false;
        }
    }
    else{
        if (!((y2 <= y) && (y <= y1))){
            // cout << "false\n";
            return false;
        }
    }
    // cout << "true\n";
    return true;
    
}

bool willDamageScreen(int x1, int y1, int x2, int y2, int xl, int yl, int xr, int yr){
    // either end is in/touches the square
    if (
        point_in_square(static_cast<double>(x1), static_cast<double>(y1), xl, yl, xr, yr) 
        || point_in_square(static_cast<double>(x2), static_cast<double>(y2), xl, yl, xr, yr)
    )
        return true;
    // calculate the intersection between line and 4 line of square
    // filter out those point in between the segment, 
    // then check if the point is in / touches screen
    // line: a1 x + b1 y = -c1
    int a1 = (y2-y1);
    int b1 = -(x2-x1);
    int c1 = -((y2-y1)*x1-(x2-x1)*y1);
    // cout << a1<< "x + "<<b1<<" y = "<<(-c1) << "\n";

    bool intersects;
    double isec_x=-5, isec_y=-5;
    
    int a2, b2, c2;
    // x=xl ==>  a2=1, b2=0, c2=-xl
    a2=1;b2=0;c2=-xl;
    getIntersection(a1, b1, c1, a2, b2, c2, intersects, isec_x, isec_y);
    if (intersects && point_in_segment(isec_x, isec_y, x1, y1, x2, y2) && point_in_square(isec_x, isec_y, xl, yl, xr, yr)){
        // cout << "DAMAGE1: ( " << isec_x << ", " << isec_y << " )\n";
        return true;
    }
    // x=xr ==>  a2=1, b2=0, c2=-xr
    a2=1;b2=0;c2=-xr;
    getIntersection(a1, b1, c1, a2, b2, c2, intersects, isec_x, isec_y);
    if (intersects && point_in_segment(isec_x, isec_y, x1, y1, x2, y2) && point_in_square(isec_x, isec_y, xl, yl, xr, yr)){
        // cout << "DAMAGE2: ( " << isec_x << ", " << isec_y << " )\n";
        return true;
    }
    // y=yl ==>  a2=0, b2=1, c2=-yl
    a2=0;b2=1;c2=-yl;
    getIntersection(a1, b1, c1, a2, b2, c2, intersects, isec_x, isec_y);
    if (intersects && point_in_segment(isec_x, isec_y, x1, y1, x2, y2) && point_in_square(isec_x, isec_y, xl, yl, xr, yr)){
        // cout << "DAMAGE3: ( " << isec_x << ", " << isec_y << " )\n";
        return true;
    }
    // y=yr ==>  a2=0, b2=1, c2=-yr
    a2=0;b2=1;c2=-yr;
    getIntersection(a1, b1, c1, a2, b2, c2, intersects, isec_x, isec_y);
    if (intersects && point_in_segment(isec_x, isec_y, x1, y1, x2, y2) && point_in_square(isec_x, isec_y, xl, yl, xr, yr)){
        // cout << "DAMAGE4: ( " << isec_x << ", " << isec_y << " )\n";
        return true;
    }

    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--){
        int xl, yl, xr, yr;
        int x1, y1, x2, y2;
        cin >> xl >> yl >> xr >> yr;
        cin >> x1 >> y1 >> x2 >> y2;
        if (willDamageScreen(x1, y1, x2, y2, xl, yl, xr, yr))
            cout << "STOP\n";
        else
            cout << "OK\n";
        
    }

}
