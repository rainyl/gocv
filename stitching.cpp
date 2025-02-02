#include "stitching.h"

CvStatus Stitcher_Create(int mode, PtrStitcher *rval)
{
    BEGIN_WRAP
    const auto ptr = cv::Stitcher::create(static_cast<cv::Stitcher::Mode>(mode));
    *rval = new cv::Ptr<cv::Stitcher>(ptr);
    END_WRAP
}

void Stitcher_Close(PtrStitcher stitcher)
{
    delete stitcher;
}

CvStatus Stitcher_Get(PtrStitcher stitcher, Stitcher *rval)
{
    BEGIN_WRAP
    *rval = stitcher->get();
    END_WRAP
}

CvStatus Stitcher_GetRegistrationResol(Stitcher stitcher, double *rval)
{
    BEGIN_WRAP
    *rval = stitcher->registrationResol();
    END_WRAP
}

CvStatus Stitcher_SetRegistrationResol(Stitcher stitcher, double inval)
{
    BEGIN_WRAP
    stitcher->setRegistrationResol(inval);
    END_WRAP
}

CvStatus Stitcher_GetSeamEstimationResol(Stitcher stitcher, double *rval)
{
    BEGIN_WRAP
    *rval = stitcher->seamEstimationResol();
    END_WRAP
}
CvStatus Stitcher_SetSeamEstimationResol(Stitcher stitcher, double inval)
{
    BEGIN_WRAP
    stitcher->setSeamEstimationResol(inval);
    END_WRAP
}

CvStatus Stitcher_GetCompositingResol(Stitcher stitcher, double *rval)
{
    BEGIN_WRAP
    *rval = stitcher->compositingResol();
    END_WRAP
}
CvStatus Stitcher_SetCompositingResol(Stitcher stitcher, double inval)
{
    BEGIN_WRAP
    stitcher->setCompositingResol(inval);
    END_WRAP
}

CvStatus Stitcher_GetPanoConfidenceThresh(Stitcher stitcher, double *rval)
{
    BEGIN_WRAP
    *rval = stitcher->panoConfidenceThresh();
    END_WRAP
}
CvStatus Stitcher_SetPanoConfidenceThresh(Stitcher stitcher, double inval)
{
    BEGIN_WRAP
    stitcher->setPanoConfidenceThresh(inval);
    END_WRAP
}

CvStatus Stitcher_GetWaveCorrection(Stitcher stitcher, bool *rval)
{
    BEGIN_WRAP
    *rval = stitcher->waveCorrection();
    END_WRAP
}
CvStatus Stitcher_SetWaveCorrection(Stitcher stitcher, bool inval)
{
    BEGIN_WRAP
    stitcher->setWaveCorrection(inval);
    END_WRAP
}

CvStatus Stitcher_GetInterpolationFlags(Stitcher stitcher, int *rval)
{
    BEGIN_WRAP
    *rval = static_cast<int>(stitcher->interpolationFlags());
    END_WRAP
}
CvStatus Stitcher_SetInterpolationFlags(Stitcher stitcher, int inval)
{
    BEGIN_WRAP
    stitcher->setInterpolationFlags(static_cast<cv::InterpolationFlags>(inval));
    END_WRAP
}

CvStatus Stitcher_GetWaveCorrectKind(Stitcher stitcher, int *rval)
{
    BEGIN_WRAP
    *rval = static_cast<int>(stitcher->waveCorrectKind());
    END_WRAP
}
CvStatus Stitcher_SetWaveCorrectKind(Stitcher stitcher, int inval)
{
    BEGIN_WRAP
    stitcher->setWaveCorrectKind(static_cast<cv::detail::WaveCorrectKind>(inval));
    END_WRAP
}

CvStatus Stitcher_EstimateTransform(Stitcher stitcher, Mats mats, Mats masks, int *rval)
{
    BEGIN_WRAP
    std::vector<cv::Mat> _mats;
    for (size_t i = 0; i < mats.length; i++)
        _mats.push_back(*mats.mats[i]);
    if (masks.length > 0)
    {
        std::vector<cv::Mat> _masks;
        for (size_t i = 0; i < masks.length; i++)
            _masks.push_back(*masks.mats[i]);
        *rval = static_cast<int>(stitcher->estimateTransform(_mats, _masks));
    }
    else
        *rval = static_cast<int>(stitcher->estimateTransform(_mats));
    END_WRAP
}

CvStatus Stitcher_ComposePanorama(Stitcher stitcher, Mat rpano, int *rval)
{
    BEGIN_WRAP
    *rval = static_cast<int>(stitcher->composePanorama(*rpano));
    END_WRAP
}
CvStatus Stitcher_ComposePanorama_1(Stitcher stitcher, Mats mats, Mat rpano, int *rval)
{
    BEGIN_WRAP
    std::vector<cv::Mat> _mats;
    for (size_t i = 0; i < mats.length; i++)
        _mats.push_back(*mats.mats[i]);
    *rval = static_cast<int>(stitcher->composePanorama(_mats, *rpano));
    END_WRAP
}

CvStatus Stitcher_Stitch(Stitcher stitcher, Mats mats, Mat rpano, int *rval)
{
    BEGIN_WRAP
    std::vector<cv::Mat> _mats;
    for (size_t i = 0; i < mats.length; ++i)
        _mats.push_back(*mats.mats[i]);
    *rval = static_cast<int>(stitcher->stitch(_mats, *rpano));
    END_WRAP
}
CvStatus Stitcher_Stitch_1(Stitcher stitcher, Mats mats, Mats masks, Mat rpano, int *rval)
{
    BEGIN_WRAP
    std::vector<cv::Mat> _mats;
    for (size_t i = 0; i < mats.length; i++)
        _mats.push_back(*mats.mats[i]);
    std::vector<cv::Mat> _masks;
    for (size_t i = 0; i < masks.length; i++)
        _masks.push_back(*masks.mats[i]);
    *rval = static_cast<int>(stitcher->stitch(_mats, _masks, *rpano));
    END_WRAP
}

CvStatus Stitcher_Component(Stitcher stitcher, IntVector *rval)
{
    BEGIN_WRAP
    std::vector<int> _rval = stitcher->component();

    (*rval).length = (int)_rval.size();
    int *vals = new int[_rval.size()];
    for (size_t i = 0; i < _rval.size(); i++)
        vals[i] = _rval.at(i);
    (*rval).val = vals;
    END_WRAP
}
