#ifdef _MDS_WITH_REDSVD
#include <redsvd/redsvd.hpp>
#else
#include <eigen3/Eigen/SVD>
#endif
#include "mds.hpp"
#include <iostream>
using namespace std;

int num=8;
int main(){
  MatrixXf d(num,num);
// 渋谷	新宿	池袋	巣鴨	上野	東京	品川	五反田
  d<< 
  0	,3609	,7880	,9026	,9217	,6385	,4742	,4092,
  3609	,0	,4328	,5911	,7410	,6046	,7679	,7477,
  7880	,4328	,0	,2666	,6275	,7305	,11326	,11469,
  9026	,5911	,2666	,0	,4069	,6284	,11504	,12003,
  9217	,7410	,6275	,4069	,0	,3744	,9886	,10871,
  6385	,6046	,7305	,6284	,3744	,0	,6157	,7230,
  4742	,7679	,11326	,11504	,9886	,6157	,0	,1592,
  4092	,7477	,11469	,12003	,10871	,7230	,1592	,0
    ;

  cout << "dist matrix:" << endl << d << endl;
  MatrixXf result(num,2);

  mds_eigen(d,result);
  cout << "result:" << endl << result << endl;

  return 1;
}
