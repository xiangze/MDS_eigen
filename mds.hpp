//http://d.hatena.ne.jp/download_takeshi/20100410/1270921957
#include <eigen3/Eigen/Dense>
#ifdef _MDS_WITH_REDSVD
#include <redsvd/redsvd.hpp>
#else
#include <eigen3/Eigen/SVD>
#endif
using namespace Eigen;

void mds_eigen(MatrixXf & d,MatrixXf & out){

  MatrixXf d2(d.rows(),d.cols());
  MatrixXf nm(d.rows(),d.cols());

  for(int i=0;i<d.rows();i++)
    for(int j=0;j<d.cols();j++)
      d2(i,j)=d(i,j)*d(i,j);

  nm.setConstant(-1./d.rows());

  for(int i=0;i<d.rows();i++)
    nm(i,i)+=1.;

  MatrixXf  inm=nm * d2* nm.transpose();
  inm/=2;

#ifdef _MDS_WITH_REDSVD
//   REDSVD::RedSVD REDSVDOfA(inm, inm.rows());
  REDSVD::RedSVD svd(inm, inm.rows());
  MatrixXf sig=svd.singularValues();
  MatrixXf u=svd.matrixU();
#else
  JacobiSVD<MatrixXf> svd(inm, ComputeThinU | ComputeThinV);
  MatrixXf sig=svd.singularValues();
  MatrixXf u=svd.matrixU();
#endif

//       out=u*sig;
  for(int i=0;i<out.rows();i++)
    for(int j=0;j<out.cols();j++)
      out(i,j)=u(i,j)*sqrt(sig(j));

}
