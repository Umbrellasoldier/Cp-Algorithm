// 点/向量
template<class T>
struct Point{
    T x;
    T y;
    Point(const T &x_=0,const T &y_=0):x(x_),y(y_){}
    
    template<class U>
    operator Point<U>(){
        return Point<U>(U(x),U(y));
    }
    Point &operator+=(const Point &p)&{
        x+=p.x;
        y+=p.y;
        return *this;
    }
    Point &operator-=(const Point &p)&{
        x-=p.x;
        y-=p.y;
        return *this;
    }
    Point &operator*=(const T &v)&{
        x*=v;
        y*=v;
        return *this;
    }
    Point &operator/=(const T &v)&{
        x/=v;
        y/=v;
        return *this;
    }
    Point operator-()const{
        return Point(-x,-y);
    }
    friend Point operator+(Point a,const Point &b){
        return a+=b;
    }
    friend Point operator-(Point a,const Point &b){
        return a-=b;
    }
    friend Point operator*(Point a,const T &b){
        return a*=b;
    }
    friend Point operator/(Point a,const T &b){
        return a/=b;
    }
    friend Point operator*(const T &a,Point b){
        return b*=a;
    }
    friend bool operator==(const Point &a,const Point &b){
        return a.x==b.x&&a.y==b.y;
    }
    friend istream &operator>>(istream &is,Point &p){
        return is>>p.x>>p.y;
    }
    friend ostream &operator<<(ostream &os,const Point &p){
        return os<<"("<<p.x<<","<<p.y<<")";
    }
};

// 直线/线段
template<class T>
struct Line{
    Point<T>a;
    Point<T>b;
    Line(const Point<T>&a_=Point<T>(),const Point<T>&b_=Point<T>()):a(a_),b(b_){}
};


// 点积：A*B=|A||B|cos(t)=A.x*B.x+A.y*B.y
template<class T>
T dot(const Point<T>&a,const Point<T>&b){
    return a.x*b.x+a.y*b.y;
}

// 叉积：AxB=|A||B|sin(t)=A.x*B.y-A.y*B.x
template<class T>
T cross(const Point<T>&a,const Point<T>&b){
    return a.x*b.y-a.y*b.x;
}

template<class T>
T square(const Point<T>&p){
    return dot(p,p);
}

// 向量取模
template<class T>
T length(const Point<T>&p){
    return sqrt(square(p));
}

// 线段长度
template<class T>
T length(const Line<T>&l){
    return length(l.a-l.b);
}

// 单位向量/归一化
template<class T>
Point<T> normalize(const Point<T>&p){
    return p/length(p);
}

// 两个向量之间的夹角
template<class T>
T angle(const Point<T>&a,const Point<T>&b){
    return acos(dot(a,b)/length(a)/length(b));
}

// 两点之间距离
template<class T>
T distance(const Point<T>&a,const Point<T>&b){
    return length(a-b);
}

// 两个向量构成平行四边形面积
template<class T>
T area(const Point<T>&a,const Point<T>&b){
    return cross(a,b);
}

// 向量逆时针旋转 t°
// [cos t,-sin t] [ax]
// [sin t,cos t]  [ay]
//=[cos t ax-sin t ay]
//   [sin t ax+cos t ay]

// 向量逆时针旋转一个角度
template<class T>
Point<T> rotate(const Point<T>&a,const T angle){
    return Point(a.x*cos(angle)-a.y*sin(angle),a.x*sin(angle)+a.y*cos(angle));
}

// 逆时针旋转90°
template<class T>
Point<T> rotate_90(const Point<T>&a){
    return Point(-a.y,a.x);
}

// 点在线段上
template<class T>
bool pointOnSegment(const Point<T>&p,const Line<T>&l){
    return cross(p-l.a,l.b-l.a)==0&&min(l.a.x,l.b.x)<=p.x&&p.x<=max(l.a.x,l.b.x)
        &&min(l.a.y,l.b.y)<=p.y&&p.y<=max(l.a.y,l.b.y);
}

// 点在直线上
template<class T>
bool pointOnLine(const Point<T>&p,const Line<T>&l){
    return cross(p-l.a,l.b-l.a)==0;
}

// 判两直线是否平行/重合
template<class T>
bool parallel(const Line<T>&l1,const Line<T>&l2){
    return cross(l1.b-l1.a,l2.b-l2.a)==0;
}

// 两直线交点
template<class T>
Point<T> lineIntersection(const Line<T>&l1,const Line<T>&l2){
    return l1.a+(l1.b-l1.a)*(cross(l2.b-l2.a,l1.a-l2.a)/cross(l2.b-l2.a,l1.a-l1.b));
}

// 点到直线距离
template<class T>
T distancePL(const Point<T>&p,const Line<T>&l){
    return abs(cross(l.a-l.b,l.a-p))/length(l);
}

// 点到线段距离
template<class T>
T distancePS(const Point<T>&p,const Line<T>&l){
    if(dot(p-l.a,l.b-l.a)<0){
        return distance(p,l.a);
    }
    if(dot(p-l.b,l.a-l.b)<0){
        return distance(p,l.b);
    }
    return distancePL(p,l);
}

// 点在直线上的投影
template<class T>
Point<T> projectionPL(const Point<T>&p,const Line<T>&l){
    return l.a+dot(p-l.a,l.b-l.a)/length(l)*normalize(l.b-l.a);
}

// 判两线段关系
// 0：不相交
// 1：严格相交
// 2：重叠
// 3：端点相交
template<class T>
tuple<int,Point<T>,Point<T>> segmentIntersection(const Line<T>&l1,const Line<T>&l2){
    if(max(l1.a.x,l1.b.x)<min(l2.a.x,l2.b.x)){
        return{0,Point<T>(),Point<T>()};
    }
    if(min(l1.a.x,l1.b.x)>max(l2.a.x,l2.b.x)){
        return{0,Point<T>(),Point<T>()};
    }
    if(max(l1.a.y,l1.b.y)<min(l2.a.y,l2.b.y)){
        return{0,Point<T>(),Point<T>()};
    }
    if(min(l1.a.y,l1.b.y)>max(l2.a.y,l2.b.y)){
        return{0,Point<T>(),Point<T>()};
    }
    if(cross(l1.b-l1.a,l2.b-l2.a)==0){
        if(cross(l1.b-l1.a,l2.a-l1.a)!=0){
            return{0,Point<T>(),Point<T>()};
        }else{
            auto maxx1=max(l1.a.x,l1.b.x);
            auto minx1=min(l1.a.x,l1.b.x);
            auto maxy1=max(l1.a.y,l1.b.y);
            auto miny1=min(l1.a.y,l1.b.y);
            auto maxx2=max(l2.a.x,l2.b.x);
            auto minx2=min(l2.a.x,l2.b.x);
            auto maxy2=max(l2.a.y,l2.b.y);
            auto miny2=min(l2.a.y,l2.b.y);
            Point<T>p1(max(minx1,minx2),max(miny1,miny2));
            Point<T>p2(min(maxx1,maxx2),min(maxy1,maxy2));
            if(!pointOnSegment(p1,l1)){
                swap(p1.y,p2.y);
            }
            if(p1==p2){
                return{3,p1,p2};
            }else{
                return{2,p1,p2};
            }
        }
    }
    auto cp1=cross(l2.a-l1.a,l2.b-l1.a);
    auto cp2=cross(l2.a-l1.b,l2.b-l1.b);
    auto cp3=cross(l1.a-l2.a,l1.b-l2.a);
    auto cp4=cross(l1.a-l2.b,l1.b-l2.b);
    
    if((cp1>0&&cp2>0)||(cp1<0&&cp2<0)||(cp3>0&&cp4>0)||(cp3<0&&cp4<0)){
        return{0,Point<T>(),Point<T>()};
    }
    
    Point p=lineIntersection(l1,l2);
    if(cp1!=0&&cp2!=0&&cp3!=0&&cp4!=0){
        return{1,p,p};
    }else{
        return{3,p,p};
    }
}

// 两线段距离
template<class T>
T distanceSS(const Line<T>&l1,const Line<T>&l2){
    if(get<0>(segmentIntersection(l1,l2))!=0){
        return 0.0;
    }
    return min({distancePS(l1.a,l2),distancePS(l1.b,l2),distancePS(l2.a,l1),distancePS(l2.b,l1)});
}


// 三角形面积：叉积/海伦公式
// 海伦公式：p=(a+b+c)/2；S=sqrt((p-a)*(p-b)*(p-c))
// 三角形四心
//(1)外心，外接圆圆心
//     三边中垂线交点。到三角形三个顶点的距离相等
//(2)内心，内切圆圆心
//     角平分线交点，到三边距离相等
//(3)垂心
//     三条垂线交点
//(4)重心
//     三条中线交点（到三角形三顶点距离的平方和最小的点，三角形内到三边距离之积最大的点）

// 任意凸多边形外角和360°，内角和(n-2)*180°

// 任意多边形面积
template<class T>
T PolygonArea(const vector<Point<T>>&p){
    T s=0;
    for(int i=1;i+1<p.size();i++){
        s+=cross(p[i]-p[0],p[i+1]-p[i]);
    }
    return s/2;
}

// 判断点是否在线段左侧
template<class T>
bool pointOnLineLeft(const Point<T>&p,const Line<T>&l){
    return cross(l.b-l.a,p-l.a)>0;
}

// 判线段是否与直线相交
template<class T>
bool segmentLineIntersection(const Line<T>&s,const Line<T>&l){
    return cross(l.b-l.a,s.a-l.a)*cross(l.b-l.a,s.b-l.a)<=0;
}


// 点是否在任意多边形内/边上
template<class T>
bool pointInPolygon(const Point<T>&a,const vector<Point<T>>&p){
    int n=p.size();
    for(int i=0;i<n;i++){
        if(pointOnSegment(a,Line(p[i],p[(i+1)% n]))){
            return true;
        }
    }
    
    int t=0;
    for(int i=0;i<n;i++){
        auto u=p[i];
        auto v=p[(i+1)%n];
        if(u.x<a.x&&v.x>=a.x&&pointOnLineLeft(a,Line(v,u))){
            t^=1;
        }
        if(u.x>=a.x&&v.x<a.x&&pointOnLineLeft(a,Line(u,v))){
            t^=1;
        }
    }
    return t==1;
}

// 皮克定理
// 一个计算点阵中顶点在格点上的多边形面积公式该公式可以表示为
// S=a+b/2-1
// 其中a表示多边形内部的点数，b表示多边形边界上的点数，S表示多边形的面积。

// 求给定点集凸包，返回上凸壳和下凸壳
template<class T>
auto getHull(vector<Point<T>>p){
    sort(p.begin(),p.end(),
        [&](auto a,auto b){
            return a.x<b.x||(a.x==b.x&&a.y<b.y);
        });
    
    vector<Point<T>> hi,lo;
    for(auto p:p){
        while(hi.size()>1&&cross(hi.back()-hi[hi.size()-2],p-hi.back())>=0){
            hi.pop_back();
        }
        while(!hi.empty()&&hi.back().x==p.x){
            hi.pop_back();
        }
        hi.push_back(p);
        while(lo.size()>1&&cross(lo.back()-lo[lo.size()-2],p-lo.back())<=0){
            lo.pop_back();
        }
        if(lo.empty()||lo.back().x<p.x){
            lo.push_back(p);
        }
    }
    return make_pair(hi,lo);
}

template<class T>
int sgn(const Point<T> &a){
    return a.y>0||(a.y==0&&a.x>0)?1:-1;
}

// 返回给定直线集合的半平面交的点集
template<class T>
vector<Point<T>> hp(vector<Line<T>>lines){
    sort(lines.begin(),lines.end(),[&](auto l1,auto l2){
        auto d1=l1.b-l1.a;
        auto d2=l2.b-l2.a;
        if(sgn(d1)!= sgn(d2)){
            return sgn(d1)==1;
        }
        
        return cross(d1,d2)>0;
    });
    deque<Line<T>>ls;
    deque<Point<T>>ps;
    for(auto l:lines){
        if(ls.empty()){
            ls.push_back(l);
            continue;
        }
        while(!ps.empty()&&!pointOnLineLeft(ps.back(),l)){
            ps.pop_back();
            ls.pop_back();
        }
        while(!ps.empty()&&!pointOnLineLeft(ps[0],l)){
            ps.pop_front();
            ls.pop_front();
        }
        if(cross(l.b-l.a,ls.back().b-ls.back().a)==0){
            if(dot(l.b-l.a,ls.back().b-ls.back().a)>0){
                if(!pointOnLineLeft(ls.back().a,l)){
                    assert(ls.size()==1);
                    ls[0]=l;
                }
                continue;
            }
            return{};
        }
        ps.push_back(lineIntersection(ls.back(),l));
        ls.push_back(l);
    }
    while(!ps.empty()&&!pointOnLineLeft(ps.back(),ls[0])){
        ps.pop_back();
        ls.pop_back();
    }
    if(ls.size()<=2){
        return {};
    }
    ps.push_back(lineIntersection(ls[0],ls.back()));
    return vector(ps.begin(),ps.end());
}

template<class T>
bool segmentInPolygon(const Line<T> &l,const vector<Point<T>> &p){
    int n=p.size();
    if(!pointInPolygon(l.a,p)){
        return false;
    }
    if(!pointInPolygon(l.b,p)){
        return false;
    }
    for(int i=0;i<n;i++){
        auto u=p[i];
        auto v=p[(i+1)%n];
        auto w=p[(i+2)%n];
        auto [t,p1,p2]=segmentIntersection(l,Line(u,v));
        
        if(t==1){
            return false;
        }
        if(t==0){
            continue;
        }
        if(t==2){
            if(pointOnSegment(v,l)&&v!=l.a&&v!=l.b){
                if(cross(v-u,w-v)>0){
                    return false;
                }
            }
        }else{
            if(p1!=u&&p1!=v){
                if(pointOnLineLeft(l.a,Line(v,u))||pointOnLineLeft(l.b,Line(v,u))){
                    return false;
                }
            }else if(p1==v){
                if(l.a==v){
                    if(pointOnLineLeft(u,l)){
                        if(pointOnLineLeft(w,l)&&pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }else{
                        if(pointOnLineLeft(w,l)||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }
                }else if(l.b==v){
                    if(pointOnLineLeft(u,Line(l.b,l.a))){
                        if(pointOnLineLeft(w,Line(l.b,l.a))&&pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }else{
                        if(pointOnLineLeft(w,Line(l.b,l.a))||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }
                }else{
                    if(pointOnLineLeft(u,l)){
                        if(pointOnLineLeft(w,Line(l.b,l.a))||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }else{
                        if(pointOnLineLeft(w,l)||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

using Real=long double;
using P=Point<Real>;
using L=Line<Real>;
constexpr Real eps=1e-7;

const Real pi=acos(-1);
// 角度结尾弧度制
// 余弦定理：c^2=a^2+b^2-2abcos(t)

template<class T>
int sign(T x){
    if(fabs(x)<eps){
        return 0;
    }
    if(x<0){
        return -1;
    }
    return 1;
}
