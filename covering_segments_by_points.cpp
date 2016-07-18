/**
 * Purpose: For a set of n segments [a1,b1],[a2,b2],...,[an,bn] find the minimum
 *          number m of points such that each segment contains at least one point.
 *          
 * Input:   First line: single integer n that specified number of segments
 *          Next n lines: segments [ai,bi]
 *
 * Constraints: 1 <= n <= 100; 0 <= ai <= bi <= 10^9
 *          
 * Output:  First line: minimum number m of points
 *          Second line: m points separated by space.
 */

#include <iostream>
#include <vector>
using namespace std;

struct segment
{
    int xmin;
    int xmax;
};

vector<segment> segments;
vector<int> refs;

/**
 * Sorts the segments worst case O(n^2).
 * This can be improved with a better sort method like Mergesort.
 * 
 * @param n length of the sequences
 */
void sortVector(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            // It is sorted by the max value of the segment
            if(segments[j].xmax > segments[j+1].xmax)
            {
                segment backup = segments[j];
                segments[j]    = segments[j+1];
                segments[j+1]  = backup;
            }
        }
    }
}

/**
 * Determines all the common points covered by the segments.
 */
void covering(int n)
{
    segment ref = segments[0];
    refs.push_back(ref.xmax);

    for(int i = 1; i < n; i++)
    {
        if(segments[i].xmin > ref.xmax)
        {
            ref = segments[i];
            refs.push_back(ref.xmax);
        }
    }

    cout << refs.size() << endl;

    for (int i = 0; i < refs.size(); ++i)
    {
        cout << refs[i];
        cout << (i + 1 < refs.size()? " " : "\n");
    }
}

int main(int argc, char const *argv[])
{
    int n, value;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        segment seg;
        cin >> seg.xmin >> seg.xmax;
        segments.push_back(seg);
    }

    // Save move is sort the segments by their max value.
    sortVector(n);
    covering(n);

    return 0;
}