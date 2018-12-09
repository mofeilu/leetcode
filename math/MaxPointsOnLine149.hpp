/*Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

*/
#include <vector>
#include <algorithm>


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Line {
public:
  Line(Point const & p1, Point const & p2) :
   _p1(p1.x, p1.y), _p2(p2.x, p2.y)
  {} 

  bool isOnLine(Point const & p) {
    // to avoid integer overflow
    return (double(p.x - _p1.x)*double(_p2.y-_p1.y) - double(_p2.x - _p1.x)*double(p.y - _p1.y) == 0);
  }

  /*bool isColinear(Line const & l) {
    return isOnLine(l._p1) && isOnLine(l._p2);
  }*/
 
  Point _p1;
  Point _p2;

};

class MaxPointsOnLine149
{
public:

    bool isSamePt(Point const & p1, Point const & p2) {
      return (p1.x == p2.x && p1.y == p2.y);
    }

    int solve(std::vector<Point>& points) {
      
      // first sort points to find degeneracy
      std::sort(points.begin(), points.end(), [](Point a, Point b){return a.x<b.x || (a.x==b.x && a.y<b.y);});
      std::vector<Point> tmpPtVec; std::vector<int> degOfPts;
      
      //tmpPtVec.push_back(points[0]);
      int lastUniquePtInd = 0;
      int currInd = 0;
      int deg = 0;

      while (currInd < points.size()) {
        if (isSamePt(points[lastUniquePtInd], points[currInd])) {
          deg++;
        } else {
          tmpPtVec.push_back(points[lastUniquePtInd]);
          degOfPts.push_back(deg);
          lastUniquePtInd = currInd;
          deg = 1;
        }
        currInd++;
        if (currInd >= points.size()) {
           tmpPtVec.push_back(points[lastUniquePtInd]);
           degOfPts.push_back(deg);
        }
      }

      points = tmpPtVec;

      // show deg
      /*for (size_t i=0; i<points.size(); ++i) {
        std::cout << "point " << i << " : " << degOfPts[i] << std::endl;
      }*/
      
      std::vector<std::pair<Line, std::vector<int> > >lines;  // for each line, store the corresponding pts
      //int maxNumOfPts = 0;

      // loop over all the pts
      for (int i=0; i<(int)points.size(); ++i) {
        // first update the # of points on line, and mark points to 
        //  be excluded for forming new line
        std::vector<bool> ptsToFormLine(i, true);  // pts from 0 to i-1 
        
        for (int j=0; j<(int)lines.size(); ++j) {
          if (lines[j].first.isOnLine(points[i])) {  // point on line
            lines[j].second.push_back(i);
            // when points on line, we need to exclude all the pts on this line
            // to form new line with current point
            for (int k=0; k<(int)lines[j].second.size(); ++k)
                   ptsToFormLine[lines[j].second[k]] = false;
          } 
        }


        for (int n=0; n<(int)ptsToFormLine.size(); ++n) {
          if (ptsToFormLine[n])
            if (!isSamePt(points[i], points[n]) ){
              Line l(points[i], points[n]);
              lines.push_back(std::pair<Line, std::vector<int> >(l, {i,n}));
            }
        }

      }

      int maxNumOfPts = 0;

      if (lines.size() == 0) {  // no line, meaning all pts degenerate
        std::cout << "no lines, all pts deg" << std::endl;
        int nPts = 0;
        for (size_t n=0; n< degOfPts.size(); ++n)
          nPts += degOfPts[n];
        return nPts;      
      }


      // summarize results;
      for (size_t i=0; i<lines.size(); ++i) {
        //std::cout << "line" << i << " : ";
        int nPts = 0;
        for (size_t n= 0; n<lines[i].second.size(); ++n) {
           //std::cout << lines[i].second[n] << ' ';
           nPts += degOfPts[lines[i].second[n]];
         }
         //std::cout << std::endl;

        if (nPts > maxNumOfPts) 
          maxNumOfPts = nPts;
      }       

      return maxNumOfPts;
    }

    

    void test()
    {
      /*std::vector<Point> points = { Point(1,1), Point(3,2), Point(5,3), Point(4,1),
      Point(2,3), Point(1,4)};*/

      //std::vector<Point> points = { Point(1,1), Point(2,2), Point(3,3)};
      std::vector<Point> points = { Point(0,0), Point(1,65536),Point(65536,0) };
      //Line line_test(Point(0,0), Point(1,65536));
      //std::cout << " is on line : " << line_test.isOnLine(Point(65536,0)) << std::endl;
      std::cout << "maxNumofPts on line: " << solve(points) << std::endl;


    }




};
