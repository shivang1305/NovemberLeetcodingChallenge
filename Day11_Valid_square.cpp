/*                                                                                     Date: 12-Nov-2020
    Day 11: Given four coordinates find out that those four cooordinates makes a square or not

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True


*/

class Solution {
public:
    //this function obtains the length between two sides
    int getLength(vector<int>& a, vector<int>& b) {
        return ((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        
        s.insert(getLength(p1, p2));
        s.insert(getLength(p1, p3));
        s.insert(getLength(p1, p4));
        s.insert(getLength(p2, p3));
        s.insert(getLength(p2, p4));
        s.insert(getLength(p3, p4));
        
        return s.size() == 2 && !s.count(0); //if the size of the set is 2 i.e. there are only two unique values of distances (side and daigonal distance) AND set does not contain zero value i.e. distance cannot be zero between any sides. then it must be a square
    }
};