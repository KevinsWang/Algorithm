/**
 * 频域滤波
 * @param originalPoints 原始数据
 * @param samplingInterval 采样间隔, 单位是秒(s)
 * @param lowpass 低通
 * @return 滤波之后的数据
 */
public static List<SamplingPoint> lowpassFromFrequencyDomain(List<SamplingPoint> originalPoints, double samplingInterval, int lowpass){
    int dataLen = originalPoints.size();
    double[] signal = new double[dataLen];
    for(int i = 0; i < originalPoints.size(); i++){
        signal[i] = originalPoints.get(i).getRealY();
    }

    double Fs = 1.0 / samplingInterval;//采样频率
    double frequencyResolution = Fs / dataLen;//频率分辨率

    //进行傅里叶变换,使用的是commons-math包里面的快速傅里叶算法
    FastFourierTransformer fft = new FastFourierTransformer(DftNormalization.STANDARD);
    Complex[] complexArr = fft.transform(signal, TransformType.FORWARD);//正向傅里叶变换

    //进行滤波,注意条件
    if(lowpass < Fs / 2.0){
        for(int i = 0; i < complexArr.length; i++){
            //对称
            if(i * frequencyResolution > lowpass && i * frequencyResolution < (Fs - lowpass)){
                complexArr[i] = new Complex(0, 0);
            }
        }
    }

    //反傅里叶变换
    Complex[] timeDomainArr = fft.transform(complexArr, TransformType.INVERSE);
    List<SamplingPoint> points = new ArrayList<>();
    for(int i = 0; i < timeDomainArr.length; i++){
        //只用获取实部，不用获取虚部(虚部理论上应该是0),实部的数据就是时域曲线
        SamplingPoint point = new SamplingPoint(i, (float) timeDomainArr[i].getReal());
        points.add(point);
    }
    return points;
}