#include<iostream>
#include<vector>
using namespace std;

struct Point{
	int x,y;
};

int orientation(Point p,Point q,Point r){
	
	int res = (q.y - p.y)*(r.x - q.x) - (r.y - q.y)*(q.x - p.x);
	return res;
}


void convex_hull_jarvis(Point p[], int n){
	
	// check whether it contains less than 3 elements.
	if( n < 3){
		cout<<"It contains only 3 Points";
		exit;
	}
	
	// find the left most element and store in variable l.
	
	int l = 0;
	for(int i=0;i<n;i++){
		
		if(p[i].x < p[l].x){
			l = i;
		}
	}
	
	// creating a vector of Point type to store convex_hull wrapping elements.
	
	vector<Point> hull;
	
	// Find the next left most element and add it in hull vector.
	
	int x=l,y;
	
	do{
		hull.push_back(p[x]);
		y = (x+1) % n ;
		
		for(int i=0;i<n;i++){
			
			if( orientation(p[x],p[i],p[y]) < 0){
				y = i;
			}
		}
		
		x = y;		
		
	}while(x != l);
	
	for(int i=0;i<hull.size();i++){
	 cout<<" {" <<hull[i].x <<" ," <<hull[i].y <<" }\n";
	}
	
}



int main(){
	Point p[] = { {0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3} };
	
	int n = sizeof(p)/sizeof(p[0]);
	convex_hull_jarvis(p,n);
	return 0;
}
