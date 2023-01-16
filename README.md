# Bezier-Curves-Graph-Application
Graph application for forming a compound Bezier curve of the third degree on the plane based on a defining polyline

Basic theoretical provisions.
Bezier curves are used in computer graphics to draw smooth curves, in CSS animations, and much more. Bezier curve is defined by anchor points. There may be two, three, four or more.
Curve properties:
1) The points are not always on the curve.
2) The degree of the curve is equal to the number of points minus one.
3) The curve is always inside the convex hull formed by the reference points:
 
Consider the de Casteljot algorithm for constructing Bezier curves using the example of 4 reference points.
 
 ![bezie](https://user-images.githubusercontent.com/103432419/212576518-e691ae07-7122-4446-a491-9e73ff96c3ad.png)
 
1) The points are connected in order by segments: 1 → 2, 2 → 3, 3 → 4.
2) For t on the segment from 0 to 1:
• Points corresponding to the current t are taken on the segments and connected. It turns out two green segments.
• On these segments, the points corresponding to the current t are taken and connected. It turns out one blue segment.
• A point corresponding to the current t is taken on the blue segment – such points make up the curve.
Formula for calculating the coordinates of the curve of the 3rd degree
Control points - Pi.
P = (1−t)^3*P1 + 3(1−t)^2*t*P2 +3(1−t)*t^2*P3 + t^3*P4

Description of the interface.

The interface is a window application with a menu and a toolbar, a drawing, fields for entering values, a button for changing values, and a field with exact coordinates of control points. Implemented txt file import and png export, with which it is possible to save previous drawings and track changes. The imported txt file must contain dotted decimal numbers in the given order: x coordinate of the point, y coordinate of the point - repeated n times.
Fixed errors when entering data using regular expressions.
The application also implements console functions and importing files through the console, which can only be performed with executable files.

Screenshots illustrating the operation of the program.
Coordinate calculation and rendering

![1](https://user-images.githubusercontent.com/103432419/212576712-cc2ce454-95aa-487f-aa7c-503b23c8a05c.png)

![2](https://user-images.githubusercontent.com/103432419/212576727-a98cdad7-40c6-42f2-938d-ce8cd1d7aab1.png)

Export

![3](https://user-images.githubusercontent.com/103432419/212576931-21bbe706-ced9-4b27-b97e-029769050359.png)

![4](https://user-images.githubusercontent.com/103432419/212576955-aa472854-d5d0-4fdb-9595-8135c7b11073.png)

Error output of unspecified file address

![6](https://user-images.githubusercontent.com/103432419/212577112-8f13f4bd-4626-4be4-b42f-a388c2ed095d.png)

Output of missing data error for file export

![5](https://user-images.githubusercontent.com/103432419/212577189-4252cacb-346d-4534-b8d6-79ffd1a58c3e.png)

File import

![7](https://user-images.githubusercontent.com/103432419/212577311-fc19ec71-9f61-46ad-a5ae-a66fe267bbfc.png)
![8](https://user-images.githubusercontent.com/103432419/212577348-bed16a3d-0ff5-4d5c-b306-40e3d94f7f1d.png)






