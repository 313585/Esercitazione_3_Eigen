#include <iostream>
#include "Eigen/Eigen"
#include <iomanip>
using namespace std;
using namespace Eigen;

void soluzione(const MatrixXd& A, const VectorXd& b, const VectorXd& x_esatta)
{
	// decomposizione PALU
	VectorXd x_PALU=A.partialPivLu().solve(b);
	std::cout<<"soluzione con decomposizione PALU: "<<x_PALU.transpose()<<std::endl;
	std::cout<<"errore relativo PALU: "<<(x_PALU-x_esatta).norm()/x_esatta.norm()<<std::endl;
	
	// decomposizione QR
	VectorXd x_QR=A.householderQr().solve(b);
	std::cout<<"soluzione con decomposizione QR: "<<x_QR.transpose()<<std::endl;
	std::cout<<"errore QR: "<<(x_QR-x_esatta).norm()/x_esatta.norm()<<std::endl;
	
}

int main()
{
	cout<<fixed<<setprecision(1)<<scientific;
	VectorXd x_esatta(2);
	x_esatta<<-1.0e+0, -1.0e+00;
	
    // esercizio parte 1
    MatrixXd A1(2,2);
    A1<< 5.547001962252291e-01, -3.770900990025203e-02,8.320502943378437e-01,-9.992887623566787e-01;
    cout<<"A1"<<A1<<endl;
    VectorXd b1(2);
    b1<<-5.169911863249772e-01, 1.672384680188350e-01;
    cout<<"b1"<<b1<<endl;
	soluzione(A1,b1,x_esatta);

	// esercizio parte 2
	MatrixXd A2(2,2);
	A2<< 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01,-8.324762492991313e-01;
	cout<<"A2"<<A2<<endl;
	VectorXd b2(2);
	b2<<-6.394645785530173e-04, 4.259549612877223e-04;
	cout<<"b2"<<b2<<endl;
	soluzione(A2,b2,x_esatta);

	// esercizio parte 3
	MatrixXd A3(2,2);
	A3<< 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01,-8.320502947645361e-01;
	cout<<"A3"<<A3<<endl;
	VectorXd b3(2);
	b3<<-6.400391328043042e-10, 4.266924591433963e-10;
	cout<<"b3"<<b3<<endl;
	soluzione(A3,b3,x_esatta);

	return 0;
}
