#ifndef BIORBD_UTILS_SPATIAL_VECTOR_H
#define BIORBD_UTILS_SPATIAL_VECTOR_H

#include "biorbdConfig.h"
#include "rbdl/rbdl_math.h"
#include "Utils/Scalar.h"

namespace BIORBD_NAMESPACE
{
namespace utils
{

///
/// \brief Wrapper of the Eigen::Matrix<double, 6, 1> or Casadi::MX(6, 1)
///
#ifdef SWIG
class BIORBD_API SpatialVector
#else
class BIORBD_API SpatialVector : public RigidBodyDynamics::Math::SpatialVector
#endif
{
public:
    ///
    /// \brief Construct SpatialVector
    ///
    SpatialVector();

    ///
    /// \brief Construct SpatialVector from Casadi SpatialVector
    /// \param other The SpatialVector to copy
    ///
    SpatialVector(
        const SpatialVector& other);

#ifndef SWIG
    ///
    /// \brief Construct SpatialVector from Casadi SpatialVector
    /// \param other The SpatialVector to copy
    ///
    SpatialVector(
        const RigidBodyDynamics::Math::SpatialVector& other);
#endif

    ///
    /// \brief Construct SpatialVector by its values
    /// \param v1 First element
    /// \param v2 Second element
    /// \param v3 Third element
    /// \param v4 Forth element
    /// \param v5 Fifth element
    /// \param v6 Sixth element
    ///
    SpatialVector(
        Scalar v1, Scalar v2, Scalar v3,
        Scalar v4, Scalar v5, Scalar v6);

#ifdef BIORBD_USE_CASADI_MATH
    ///
    /// \brief Construct SpatialVector from Casadi SpatialVector
    /// \param v The SpatialVector to copy
    ///
    SpatialVector(
        const casadi::MX& v);

    ///
    /// \brief Construct SpatialVector from Casadi matrix
    /// \param other The SpatialVector to copy
    ///
    SpatialVector(
        const RBDLCasadiMath::MX_Xd_SubMatrix& m);
#endif

#ifndef SWIG
    ///
    /// \brief operator= For submatrices
    /// \param other The SpatialVector to copy
    ///
    void operator=(
        const SpatialVector& other);
#ifdef BIORBD_USE_EIGEN3_MATH
    ///
    /// \brief Allow the use operator= on SpatialVector
    /// \param other The other matrix
    ///
    template<typename OtherDerived>
    SpatialVector& operator=(const Eigen::MatrixBase <OtherDerived>&
                                            other)
    {
        this->Eigen::Matrix<double, 6, 1>::operator=(other);
        return *this;
    }
#endif
#ifdef BIORBD_USE_CASADI_MATH
    ///
    /// \brief operator= For submatrices
    /// \param other The SpatialVector to copy
    ///
    void operator=(
        const RBDLCasadiMath::MX_Xd_SubMatrix& other);

    ///
    /// \brief operator= For submatrices
    /// \param other The SpatialVector to copy
    ///
    void operator=(
        const casadi::MX& other);
#endif

#endif
};

}
}

#endif // BIORBD_UTILS_SPATIAL_VECTOR_H
