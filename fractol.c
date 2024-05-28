
#include "fractol.h"



int galaxy_dream_palette[] = {
    0x191971, 0x201e75, 0x262278, 0x2b277c, 0x312c7f, 0x363183, 0x3b3586, 0x403a8a,
    0x453f8d, 0x4a4491, 0x4f4995, 0x544e98, 0x59539c, 0x5e589f, 0x635da3, 0x6862a6,
    0x6d67aa, 0x726cad, 0x7671b1, 0x7b77b4, 0x807cb8, 0x8581bb, 0x8a87bf, 0x8f8cc2,
    0x9591c6, 0x9a97c9, 0x9f9ccd, 0xa4a2d0, 0xa9a7d4, 0xaeadd7, 0xb4b2db, 0xb9b8de,
    0xbebde2, 0xc4c3e5, 0xc9c9e9, 0xcfceec, 0xd4d4f0, 0xdadaf3, 0xdfdff7, 0xe5e5fa
    };
int galaxy_dream_compl = 0xFFD700;


int ocean_breeze_palette[] = {
    0x00d1c0, 0x00cfc1, 0x00cdc2, 0x00cbc2, 0x00c9c3, 0x00c6c4, 0x00c4c4, 0x00c2c5,
    0x00c0c6, 0x00bec6, 0x00bbc7, 0x00b9c7, 0x00b7c7, 0x00b4c7, 0x00b2c7, 0x00b0c7,
    0x00adc7, 0x00abc7, 0x00a9c7, 0x00a6c7, 0x00a4c7, 0x00a2c6, 0x00a0c6, 0x009dc6,
    0x009bc5, 0x0099c5, 0x0096c5, 0x0094c5, 0x0092c5, 0x008fc4, 0x008dc3, 0x008bc2,
    0x0088c1, 0x0086c0, 0x0083bf, 0x0081be, 0x007ebc, 0x007cbb, 0x0079ba, 0x0077b8
};
int ocean_breeze_compl = BLACK;


int cosmic_nebula_palette[] = {
    0x993399, 0x9c3399, 0x9e329a, 0xa1329a, 0xa4319a, 0xa6319b, 0xa9309b, 0xac309b,
    0xaf2f9b, 0xb12f9c, 0xb42e9c, 0xb72e9c, 0xb92d9c, 0xbc2c9c, 0xbf2b9c, 0xc12b9c,
    0xc42a9c, 0xc7299c, 0xc9289c, 0xcc289c, 0xcf279b, 0xd1269b, 0xd4259b, 0xd7249b,
    0xd9239a, 0xdc229a, 0xde219a, 0xe12099, 0xe41f99, 0xe61e98, 0xe91d98, 0xeb1c97,
    0xee1b97, 0xf01a96, 0xf31996, 0xf51895, 0xf81794, 0xfa1693, 0xfd1593, 0xff1492
};
int cosmic_nebula_compl = 0x40E0D0;


int mystic_midnight_palette[] = {
    0x191971, 0x2b1974, 0x3a1876, 0x471779, 0x53167a, 0x5f137b, 0x6a117c, 0x750e7c,
    0x800a7c, 0x8a067c, 0x94027b, 0x9e007a, 0xa80078, 0xb10077, 0xba0274, 0xc20772,
    0xca0f6f, 0xd2176c, 0xd91f69, 0xe02766, 0xe72f62, 0xed385e, 0xf2405a, 0xfb5152,
    0xff5a4e, 0xff6349, 0xff6c44, 0xff7540, 0xff7e3b, 0xff8838, 0xff9135, 0xff9a31,
    0xffa32a, 0xffac1e, 0xffb516, 0xffbe0e, 0xffc706, 0xffd001, 0xffd900
};
int mystic_midnight_compl = 0xffd900;


int twilight_serenade_palette[] = {
    0x473d8a, 0x4f3e8b, 0x573f8d, 0x5f408e, 0x66418f, 0x6d428f, 0x744390, 0x7b4490,
    0x814591, 0x884691, 0x8e4791, 0x944991, 0x9a4a91, 0xa04b90, 0xa64d90, 0xac4f8f,
    0xb1518f, 0xb6538e, 0xbb558d, 0xc0578c, 0xc55a8c, 0xca5c8b, 0xce5f8a, 0xd26289,
    0xd66587, 0xda6886, 0xde6b85, 0xe26f84, 0xe57283, 0xe87682, 0xeb7a81, 0xee7e80,
    0xf1827f, 0xf4867e, 0xf68a7d, 0xf88e7c, 0xfa937c, 0xfc977b, 0xfe9b7a, 0xffa07a
};
int twilight_serenade_compl = 0x32CD32;


int summer_citrus_palette[] = {
    0xff6347, 0xff6646, 0xff6944, 0xff6c43, 0xff6f41, 0xff7240, 0xff753e, 0xff783c,
    0xff7b3b, 0xff7e39, 0xff8137, 0xff8436, 0xff8734, 0xff8a32, 0xff8d31, 0xff902f,
    0xff932d, 0xff962b, 0xff9929, 0xff9c27, 0xff9f25, 0xffa223, 0xffa521, 0xffa81f,
    0xffab1d, 0xffae1a, 0xffb118, 0xffb516, 0xffb813, 0xffbb10, 0xffbe0e, 0xffc10b,
    0xffc408, 0xffc706, 0xffca04, 0xffcd02, 0xffd001, 0xffd300, 0xffd600, 0xffd900
};
int summer_citrus_compl = 0x4682B4;


int ocean_blue_palette[] = {
    0x2f3293, 0x2b3899, 0x263d9e, 0x2043a4, 0x1848a9, 0x0c4eae, 0x0053b3, 0x0058b8,
    0x005ebd, 0x0063c1, 0x0069c4, 0x006ec5, 0x0074c6, 0x0079c8, 0x007eca, 0x0083cd,
    0x0088cf, 0x008dd2, 0x0092d5, 0x0097d8, 0x009cda, 0x00a1dd, 0x00a6e0, 0x00abe3,
    0x00b1e6, 0x00b6e8, 0x00bbeb, 0x00c0ee, 0x00c6f0, 0x00cbf3, 0x00d0f5, 0x00d6f7,
    0x00dbf9, 0x00e1fb, 0x00e6fc, 0x00ebfd, 0x00f0fd, 0x00f5fe, 0x00fafe, 0x19ffff
};
int ocean_blue_compl = BLACK;


int celestial_palette[] = {
    0x1d2672, 0x252673, 0x2c2674, 0x322775, 0x382776, 0x3d2777, 0x432777, 0x482778,
    0x4d2779, 0x522679, 0x572679, 0x5c267a, 0x61267a, 0x65267a, 0x6a267a, 0x6e257a,
    0x732579, 0x772579, 0x7b2579, 0x7f2578, 0x832578, 0x872577, 0x8b2577, 0x8f2576,
    0x932575, 0x972574, 0x9b2673, 0x9e2672, 0xa22771, 0xa52870, 0xa9296f, 0xac2a6e,
    0xaf2b6d, 0xb22c6c, 0xb52e6a, 0xb82f69, 0xbb3167, 0xbe3366, 0xc03565, 0xc33763
};
int celestial_compl = 0x00FFFF;


int south_pacific[] = {
    0x023140, 0x033443, 0x033746, 0x043a4a, 0x053c4d, 0x063f50, 0x084254, 0x094557,
    0x0a485a, 0x0c4b5e, 0x0d4e61, 0x0e5165, 0x105568, 0x11586b, 0x135b6f, 0x145e72,
    0x166176, 0x17647a, 0x18677d, 0x1a6b81, 0x1b6e84, 0x1d7188, 0x1e748c, 0x20788f,
    0x217b93, 0x237e97, 0x24829a, 0x26859e, 0x2788a2, 0x298ca6, 0x2a8fa9, 0x2c92ad,
    0x2d96b1, 0x2f99b5, 0x309db9, 0x32a0bc, 0x33a4c0, 0x35a7c4, 0x36aac8, 0x38aecc
};
int south_pacific_compl = BLACK;


int mypalette1[] = {
    0x4e8c31, 0x528e30, 0x55902f, 0x59922e, 0x5d942d, 0x60962c, 0x64982a, 0x689929,
    0x6c9b28, 0x709d26, 0x749f25, 0x78a123, 0x7ca222, 0x80a420, 0x84a61f, 0x89a81d,
    0x8da91b, 0x92ab19, 0x96ad17, 0x9aae15, 0x9fb013, 0xa4b110, 0xa8b30e, 0xadb40b,
    0xb2b608, 0xb7b706, 0xbbb903, 0xc0ba01, 0xc5bb00, 0xcabd00, 0xcfbe00, 0xd4bf00,
    0xdac000, 0xdfc200, 0xe4c300, 0xe9c400, 0xefc500, 0xf4c600, 0xfac700, 0xffc800
};
int mypalette1_compl = 0x1E212B;


int mypalette2[] = {
    0x255b98, 0x2c5a9a, 0x32599b, 0x38589c, 0x3e569d, 0x45559e, 0x4b539e, 0x51519e,
    0x57509e, 0x5c4e9e, 0x624c9d, 0x68499c, 0x6d479b, 0x734499, 0x784197, 0x7d3f95,
    0x833b92, 0x87388f, 0x8c348c, 0x913189, 0x952d85, 0x992881, 0x9d237d, 0xa11e78,
    0xa41874, 0xa7116f, 0xaa086a, 0xad0065, 0xaf005f, 0xb1005a, 0xb30054, 0xb4004e,
    0xb50048, 0xb60042, 0xb6003c, 0xb60036, 0xb6002f, 0xb50029, 0xb40022, 0xb3001b
};
int mypalette2_compl = 0x262626;


int mypalette3[] = {
    0x306cab, 0x3670ad, 0x3b73b0, 0x4177b2, 0x467bb4, 0x4c7fb6, 0x5182b9, 0x5686bb,
    0x5b8abd, 0x618dbf, 0x6691c2, 0x6b95c4, 0x7099c6, 0x759cc8, 0x7aa0cb, 0x80a4cd,
    0x85a7cf, 0x8aabd1, 0x8fafd3, 0x94b3d5, 0x9ab6d8, 0x9fbada, 0xa4bedc, 0xa9c2de,
    0xaec6e0, 0xb4c9e2, 0xb9cde4, 0xbed1e6, 0xc4d5e9, 0xc9d9eb, 0xcedced, 0xd4e0ef,
    0xd9e4f1, 0xdee8f3, 0xe4ecf5, 0xe9f0f7, 0xeff3f9, 0xf4f7fb, 0xfafbfd, 0xffffff
};
int mypalette3_compl = 0x141B41;


int mypalette4[] = {
    0x00ff2a, 0x00f829, 0x00f227, 0x00eb26, 0x00e424, 0x00de23, 0x00d722, 0x00d120,
    0x00ca1f, 0x00c41e, 0x00bd1c, 0x00b71b, 0x00b11a, 0x00ab18, 0x00a417, 0x009e16,
    0x009814, 0x009213, 0x008c12, 0x008611, 0x00800f, 0x007a0e, 0x00740d, 0x006e0c,
    0x00690b, 0x006309, 0x005d08, 0x005807, 0x005206, 0x004d06, 0x004705, 0x004204,
    0x003d03, 0x003803, 0x003302, 0x002e02, 0x002902, 0x002401, 0x001f01, 0x001801
};


int mypalette4_compl = BLACK;

int burning_ship[] = {
    0x2e0000, 0x300000, 0x310000, 0x330000, 0x350000, 0x360000, 0x380000, 0x3a0000,
    0x3b0000, 0x3d0000, 0x3f0000, 0x410000, 0x420000, 0x440000, 0x460000, 0x480000,
    0x490000, 0x4b0000, 0x4d0000, 0x4f0000, 0x500000, 0x520000, 0x540000, 0x560000,
    0x580000, 0x5a0000, 0x5b0000, 0x5d0000, 0x5f0000, 0x610000, 0x630000, 0x650000,
    0xF80000, 0xF80000, 0xF80000, 0xF80000, 0xB9961F, 0xB9961F, 0xB9961F, 0xB9961F
};

int burning_ship_compl = BLACK;

double scale(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

t_complex_num complex_num_sum(t_complex_num z1, t_complex_num z2)
{
    t_complex_num result;

    result.real = z1.real + z2.real;
    result.imaginary = z1.imaginary + z2.imaginary;
    return result;

}

t_complex_num complex_num_square(t_complex_num z)
{
    t_complex_num   result;

    result.real = (z.real * z.real) - (z.imaginary * z.imaginary);
    result.imaginary = 2 * z.real *z.imaginary;
    return result;
}

/*
    5 + 3i * 5 + 3i
    5*5 + 5+3i + 3i*5 + 3i*3i
    25 + 2*(5+3i) + 3i*3i
*/

// from 0------100 to 0-----20
// (2 - -2) * (68 - 0) / (100 - 0) + -2

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->addr + offset) = color;
}

int find_closest_number(int *numbers, int length, int index) {
    if (length <= 0) {
        printf("Array length should be greater than zero.\n");
        return 0;
    }

    int closest_number = numbers[0];
    int min_difference = abs(numbers[0] - index);

    for (int i = 1; i < length; i++) {
        int difference = abs(numbers[i] - index);
        if (difference < min_difference) {
            min_difference = difference;
            closest_number = numbers[i];
        }
    }

    return closest_number;
}

void    mandelbrot_julia_switch(t_complex_num *z, t_complex_num *c, t_fractal *fractal)
{
    if(ft_strncmp(fractal->name, "julia", 5) == 0)
    {
        c->real = fractal->julia_x;
        c->imaginary = fractal->julia_y;
    }
    else
    {
        c->real = z->real;
        c->imaginary = z->imaginary;
    }

}

t_complex_num complex_mp_num(t_complex_num z, double num)
{
    z.real = z.real * num;
    z.imaginary = z.imaginary * num;
    return z;
}
t_complex_num complex_minus_complex(t_complex_num z, t_complex_num z2)
{
    z.real = z.real - z2.real;
    z.imaginary = z.imaginary - z2.imaginary;
    return z;
}

t_complex_num complex_plus_num(t_complex_num z, double num)
{
    z.real = z.real + num;
    return z;
}

void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex_num   z;
    t_complex_num   c;
    int             i;
    int             color;
    int             is_fractal_burning_ship;
    int             is_fractal_phoenix; 
    t_complex_num   tmp; 
    t_complex_num   tmp2;
    
    is_fractal_burning_ship = 0;
    if(ft_strncmp(fractal->name, "burning_ship", 12) == 0)
        is_fractal_burning_ship = 1;

    is_fractal_phoenix = 0;
    if(ft_strncmp(fractal->name, "phoenix", 7) == 0)
        is_fractal_phoenix = 1;

    z.real = (scale(x, -2, 1, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.imaginary = (scale(y, -1.5, 1.5, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

    mandelbrot_julia_switch(&z, &c, fractal);
    
    tmp.real = 0;
    tmp.imaginary = 0;
    tmp2.real = 0;
    tmp2.imaginary = 0;
    i = 0;
    while (i < fractal->iterations)
    {
        if(is_fractal_burning_ship)
        {
            if (z.real < 0)
                z.real = -z.real;
            if(z.imaginary < 0)
                z.imaginary = -z.imaginary;  
        }
        if(is_fractal_phoenix)
        {
            tmp2 = z;
            z = complex_minus_complex(complex_num_square(z),complex_mp_num(tmp, 0.5));
            z.real = z.real + 0.56667;
            tmp = tmp2;
            tmp2 = z;
        }
        else
            z = complex_num_sum(complex_num_square(z), c);
        
        if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->escape_value)
        {
            // color = scale(i, BLACK, WHITE, 0, fractal->iterations);
            // color = ((0xE6E6FA - 0x191970) / fractal->iterations) * i;
            color = mypalette4[39 - (int)scale(i, 0, 39, 0, fractal->iterations)];
            my_mlx_pixel_put(&fractal->img, x, y, color);
            return ;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->img, x, y, WHITE);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while(++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
            // printf("x = %d ---- y = %d\n", x, y);
            // my_mlx_pixel_put(&fractal->img, x, y, CYAN);
        }
        
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img, 0, 0);
}
int destroy_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
    mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
    exit(EXIT_SUCCESS);
    return 0;
}
int mousedown_handler(int button, int x, int y, t_fractal *fractal)
{
    if(button == 4)
    {
        fractal->zoom *= 0.95;
        fractal->range /= 1.05;
    }
    else if(button == 5)
    {
        fractal->zoom *= 1.05;
        fractal->range *= 1.05;
    }
    fractal_render(fractal);
    return 0;
}

int keydown_handler(int keycode, t_fractal *fractal)
{
    if (keycode == 53)
    {
        destroy_handler(fractal);
    }
    if (keycode == 123)
        fractal->shift_x -= fractal->range / 8;
    if (keycode == 124)
        fractal->shift_x += fractal->range / 8;
    if (keycode == 125)
        fractal->shift_y -= fractal->range / 8;
    if (keycode == 126)
        fractal->shift_y += fractal->range / 8;
    if (keycode == 69)
        fractal->iterations += 5;
    if (keycode == 78)
        fractal->iterations -= 5;

    fractal_render(fractal);

    return 0;
}

static void event_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, ON_KEYDOWN, 0, keydown_handler, fractal);
    mlx_hook(fractal->mlx_window, ON_MOUSEDOWN, 0, mousedown_handler, fractal);
    mlx_hook(fractal->mlx_window, ON_DESTROY, 0, destroy_handler, fractal);
}

static void malloc_failed(void)
{
    perror("malloc failed");
    exit(EXIT_FAILURE);
}


void    fractal_init(t_fractal  *fractal)
{
    if (!fractal )
        return ;
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        malloc_failed();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        free(fractal->mlx_connection);
        malloc_failed();
    }
    fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        free(fractal->mlx_connection);
        malloc_failed();
    }
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &(fractal->img.bits_per_pixel), &(fractal->img.line_lenght), &(fractal->img.endian));
}

int main (int argc, char **argv)
{
    t_fractal   fractal;
    fractal.name = argv[1];
    fractal.escape_value = 4;
    fractal.iterations = 100;
    fractal.shift_x = 0.0;
    fractal.shift_y = 0.0;
    fractal.zoom = 1.0;
    fractal.range = 3.0;
    printf("fractal name : %s\n", fractal.name);
    if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) 
    || (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12))
    || (argc == 2 && !ft_strncmp(argv[1], "phoenix", 7))
    || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        if (argc == 4)
        {
            fractal.julia_x = (ft_atod(argv[2]));
            printf("julia real : %f\n", fractal.julia_x);
            fractal.julia_y = (ft_atod(argv[3]));
            printf("julia imaginary : %f\n", fractal.julia_y);
        }
        fractal_init(&fractal);
        fractal_render(&fractal);
        event_init(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
