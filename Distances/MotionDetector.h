#ifndef __MOTION_DETECTOR_H__
#define __MOTION_DETECTOR_H__ 

class MotionDetector {
    public:
        MotionDetector(unsigned int samplingTimeMillis, float detectionThreshold) :
            _samplingTimeMillis(samplingTimeMillis),
            _currentAverage(0.0),
            _previousAverage(0.0),
            _oldestAverage(0.0),
            _detectionThreshold(detectionThreshold),
            _numSamples(0)
        {
            reset();
        }

        void sample(unsigned int timeSinceLastSampleMillis, unsigned int value);
        float getAverage();
        void reset();
        bool isMovementDetected();

    private:
        unsigned int _timeSinceResetMillis;
        const unsigned int _samplingTimeMillis;
        float _currentAverage;
        float _previousAverage;
        float _oldestAverage;
        float _detectionThreshold;
        unsigned int _numSamples;

        void addValueToAverage(unsigned int value);
        void detectAndHandleTimeout(unsigned int timeSinceLastSampleMillis);
};

#endif
