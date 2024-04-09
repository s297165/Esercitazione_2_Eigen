#include <iostream>
#include "Eigen/Eigen"
#include <Eigen/QR>
using Eigen::MatrixXd;
using Eigen::VectorXd;

int main()
{
    MatrixXd A1(2,2);
    A1 << 5.547001962252291e-01, -3.770900990025203e-02, 8.320502943378437e-01, -9.992887623566787e-01;
    VectorXd b1(2);
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;
    VectorXd x1Lu = A1.fullPivLu().solve(b1);
    VectorXd x_ex(2);
    x_ex << -1.0e+0, -1.0e+00;
    std::cout << "L'errore relativo associato alla fattorizzazione PALU della matrice A1 e': " << (x1Lu-x_ex).norm()/x_ex.norm() << std::endl;
    VectorXd x1qr=A1.fullPivHouseholderQr().solve(b1);
    std::cout << "L'errore relativo associato alla fattorizzazione QR della matrice A1 e': " << (x1qr-x_ex).norm()/x_ex.norm() << "\n";

    MatrixXd A2(2,2);
    A2 << 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01, -8.324762492991313e-01;
    VectorXd b2(2);
    b2 << -6.394645785530173e-04,  4.259549612877223e-04;
 VectorXd x2Lu = A2.fullPivLu().solve(b2);
    std::cout << "L'errore relativo associato alla fattorizzazione PALU della matrice A2 e': " << (x2Lu-x_ex).norm()/x_ex.norm() << std::endl;
    VectorXd x2qr=A2.fullPivHouseholderQr().solve(b2);
    std::cout << "L'errore relativo associato alla fattorizzazione QR della matrice A2 e' :" << (x2qr-x_ex).norm()/x_ex.norm() << std::endl;

    MatrixXd A3(2,2);
    A3 << 5.547001962252291e-01, -5.547001955851905e-01,  8.320502943378437e-01, -8.320502947645361e-01;
    VectorXd b3(2);
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;
    VectorXd x3Lu = A3.fullPivLu().solve(b3);
    std::cout << "L'errore relativo associato alla fattorizzazione PALU della matrice A3 e' :" << (x3Lu-x_ex).norm()/x_ex.norm() << std::endl;
    VectorXd x3qr=A3.fullPivHouseholderQr().solve(b3);
    std::cout << "L'errore relativo associato alla fattorizzazione QR della matrice A3 e' :" << (x3qr-x_ex).norm()/x_ex.norm() << std::endl;

    return 0;
}
