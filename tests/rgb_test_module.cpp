// Author: Sudeep Pillai (spillai@csail.mit.edu)
// License: BSD
// Last modified: Sep 14, 2014

// Wrapper for most external modules
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <exception>

// Opencv includes
#include <opencv2/opencv.hpp>

// np_opencv_converter
#include "np_opencv_converter.hpp"

namespace py = boost::python;

cv::Mat rgb_test(const cv::Mat &in) {
    if (in.channels() != 3) {
        std::cout << "Input image not RGB: " << in.size() << std::endl;
        return in;
    }
    cv::Mat out;
    cv::cvtColor(in, out, CV_BGR2GRAY);
    return out;
}

// Wrap a few functions and classes for testing purposes
namespace fs { namespace python {

BOOST_PYTHON_MODULE(rgb_test_module)
{
  // Main types export
  fs::python::init_and_export_converters();
  py::scope scope = py::scope();

  // Basic test
  py::def("rgb_test", &rgb_test);
}

} // namespace fs
} // namespace python
