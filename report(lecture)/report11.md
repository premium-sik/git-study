## lec11
```
#include <stdio.h>

typedef unsigned int t_rgba;

#define fromRGBA(r,g,b,a) ((((r)&0xff)<<24)|(((g)&0xff)<<16)|(((b)&0xff)<<8)|((a)&0xff));
#define F_NUM_1_255     (1.0f/255.0f)

t_rgba mul(t_rgba c1, t_rgba c2)
{
        float r1,g1,b1,a1;
        float r2,g2,b2,a2;
        int ir, ig, ib, ia;
        r1 = (float) ((c1 >> 24) & 0xff) * F_NUM_1_255;
        g1 = (float) ((c1 >> 16) & 0xff) * F_NUM_1_255;
        b1 = (float) ((c1 >>  8) & 0xff) * F_NUM_1_255;
        a1 = (float) ((c1 >>  0) & 0xff) * F_NUM_1_255;

        r2 = (float) ((c2 >> 24) & 0xff) * F_NUM_1_255;
        g2 = (float) ((c2 >> 16) & 0xff) * F_NUM_1_255;
        b2 = (float) ((c2 >>  8) & 0xff) * F_NUM_1_255;
        a2 = (float) ((c2 >>  0) & 0xff) * F_NUM_1_255;
        ir = (int) ((r1 * r2) * 255.0f);
        ig = (int) ((g1 * g2) * 255.0f);
        ib = (int) ((b1 * b2) * 255.0f);
        ia = (int) ((a1 * a2) * 255.0f);

        return fromRGBA(ir, ig , ib, ia);
}

t_rgba mul_int(t_rgba c1, t_rgba c2)
{
        unsigned int r1, g1, b1, a1;
        unsigned int r2, g2, b2, a2;
        unsigned int r,g,b,a;
        r1 = (c1 >> 24)&0xff; r2 = (c2 >> 24)&0xff;
        g1 = (c1 >> 16)&0xff; g2 = (c2 >> 16)&0xff;
        b1 = (c1 >>  8)&0xff; b2 = (c2 >>  8)&0xff;
        a1 = (c1 >>  0)&0xff; a2 = (c2 >>  0)&0xff;

        r = (r1*r2) / 255;
        g = (g1*g2) / 255;
        b = (b1*b2) / 255;
        a = (a1*a2) / 255;

        return fromRGBA(r,g,b,a);
}
int main()
{
        int red, green, blue, alpha;
        t_rgba rgba_1, rgba_2;
        // input value must be in 0~255 : 0.0~1.0
        // rgba_1 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]
        printf("Input 4 values with 0~255\n");
        scanf("%d %d %d %d", &red, &green, &blue, &alpha);
        rgba_1 = fromRGBA(red, green, blue, alpha);
        printf("%d %d %d %d : %u 0x%08x\n", red, green, blue, alpha, rgba_1, rgba_1);
        rgba_2 = mul(rgba_1, rgba_1);
        printf("%d %d %d %d : %u 0x%08x\n", red, green, blue, alpha, rgba_2, rgba_2);
        rgba_2 = mul_int(rgba_1, rgba_1);
        printf("%d %d %d %d : %u 0x%08x\n", red, green, blue, alpha, rgba_2, rgba_2);
}
```
* ![lec11-1](../Image/lec11-1.jpeg)
* 위 사진은 입력값을 전부 255로 했을 때의 결과이다.
* rbga를 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]과 같이 8비트 간격으로 만들기 위해 전처리 구분에서 0xff과 곱셉 연산 후 각각 24, 16, 8 비트 왼쪽 쉬프트 연산을 해주는 과정을 ``` #define fromRGBA ``` 을 통해 처리해준다.
* 같은 결과값을 얻기 위해 위의 fromRGBA에서 얻은 rgba_1를 mul, mul2에 unsigned int 형태로 넣어 계산한다. 
* 이때 rgba에서 곱셉은  a, b가 있다면 ((a x b)/255)/255로 진행되기 때문에 mul함수에서도 보면 각각의 색깔을 1, 2로 나누고 다시 >> 과 &연산으로 본래의 값으로 변경 후, cpp에서 선언한 1.0f/255.0f를 나누어주는 것을 확인할 수있다. 그리고 위의 곱셈식에 따라 둘을 곱한 후 다시 256을 곱해주고 다시 fromRGBA를 했줌으로써 같은 결과값을 지니는 ir, ig, ib, ia를 얻을 수 있다.
* 결국에 곱셈은 (iaxib)x256 인 것을 알 수 있는데 그래서 mul2에서는 r1과 r2에 255를 나누지 않고 둘을 & 연산 후 곱하여 255을 나눠주고 그 결과 값을 fromRGBA에 넣어준다. 결국 같은 결과값이 나오게 된다. 
