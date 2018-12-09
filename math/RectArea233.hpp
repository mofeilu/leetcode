/*Find the total area covered by two rectilinear
 rectangles in a 2D plane. Each rectangle is defined by its bottom left 
 corner and top right corner as shown in the figure.

Rectangle Area

Example:
Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:
Assume that the total area is never beyond the maximum possible value of int.*/

#include <math.h>

class RectArea233
{
public:
	int solve(int A, int B, int C, int D, int E, int F, int G, int H) {

     int xOverlap = 0;
     int yOverlap = 0;

     if ( (E>=A && E<=C) || (A>=E && A<=G) )
       xOverlap = std::min(C,G) - std::max(A,E);
     if ( (F>=B && F<=D) || (B>=F && B<=H) )
       yOverlap = std::min(D,H) - std::max(B,F);

     return (C-A)*(D-B) + (G-E)*(H-F) - xOverlap*yOverlap;


	}


	void test()
	{
		int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
    std::cout<< "input rects : " << '(' << A << ',' << B << ')' << ' '
             << '(' << C << ',' << D << ')' << "\n"
             << '(' << E << ',' << F << ')' << ' '
	           << '(' << G << ',' << H << ')' << "\n";


    std::cout << "area = " << solve(A, B, C, D, E, F, G, H) << "\n";

  } 


};
