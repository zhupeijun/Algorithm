struct point
{
    double x,y;
};
struct line
{
    double a,b,c;
};
int dblcmp(double d)
{
    if(fabs(d) < eps) return 0;
    if(d > 0) return 1;
    else return -1;
}
double det(double x1,double y1,double x2,double y2)
{
    return x1 * y2 - x2 * y1;
}
double dot(double x1,double y1,double x2,double y2)
{
    return x1 * x2 + y1 * y2;
}
//���AB �� AC >0 C����� <0 C���Ҳ� =0 ����
double mulc(point a,point b,point c)
{
    return det(b.x - a.x,b.y - a.y,c.x - a.x,c.y - a.y);
}
//���CA * CB =0 C��˵��غ� <0 C���߶��ڲ� >0 C���߶��ⲿ
double muld(point a,point b,point c)
{
    return dot(a.x - c.x,a.y - c.y,b.x - c.x,b.y - c.y);
}
//�߶��н�
int cross(point a,point b,point c,point d)
{
    int d1,d2,d3,d4;
    //double s1,s2,s3,s4;
    d1 = dblcmp(mulc(a,b,c));
    d2 = dblcmp(mulc(a,b,d));
    d3 = dblcmp(mulc(c,d,a));
    d4 = dblcmp(mulc(c,d,b));
    //�淶�ཻ
    if((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 1;
    else
    //�ǹ淶�ཻ
    if((d1 == 0 && muld(a,b,c) <= 0)||(d2 == 0 && muld(a,b,d) <= 0)
     ||(d3 == 0 && muld(c,d,a) <= 0)||(d4 == 0 && muld(c,d,b) <= 0)) return 1;
    return 0;
}
//�������
double plen(point a,point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
//�����ȡֱ�߷���
//ax + by + c = 0;
//a = y1 - y2; b = x2 - x1;c = y1(x1 - x2) - x1(y1 - y2);
line p2line(point a,point b)
{
    line res;
    res.a = a.y - b.y;
    res.b = b.x - a.x;
    res.c = a.y * (a.x - b.x) - a.x * (a.y - b.y);
    return res;
}
//���׹�ʽ�����������
//S = sqrt(p*(p-a)*(p-b)*(p-c));p = (a+b+c)/2;
double Heron(double a,double b,double c)
{
    double p = (a + b + c)/2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}
//�����Ҷ������������ڽ�
//cosA = (c^2 + b^2 - a^2)/(2*b*c)
double triA(double a,double b,double c)
{
    return acos((c * c + b * b - a * a) / (2 * b * c));
}
//�������
//�н�Ϊangle �뾶Ϊr
double Sector_S(double angle,double r)
{
    return (angle * r * r)/2;
}
//��Բ�ཻ�����
double Circle2S(double x1,double y1,double r1,double x2,double y2,double r2)
{
    double dis = plen(x1,y1,x2,y2);
    double R = max(r1,r2);
    double r = min(r1,r2);
    if(dblcmp(dis - (R + r)) >= 0) return 0;
    if(dblcmp(dis - (R - r)) <= 0) return PI*r*r;
    double Se1 = Sector_S(triA(r2,r1,dis),r1)*2;
    double Se2 = Sector_S(triA(r1,r2,dis),r2)*2;
    double triS = Heron(r1,r2,dis)*2;
    return Se1 + Se2 - triS;
}