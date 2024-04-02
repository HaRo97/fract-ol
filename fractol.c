
#include "fractol.h"


// 2 tipi di prompt
// fractol mandelbrot
// fractol julia <parte reale> <i>

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
    // char    *dst;
    int offset;

    offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->addr + offset) = color;

    // dst = img->addr + ((y * img->line_lenght) + (x * (img->bits_per_pixel / 8)));
    // *(unsigned int*)dst = color;
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

    z.real = (scale(x, -2, 2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.imaginary = (scale(y, -2, 2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

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
        // printf("z(%d) = %f + %f\n", i, z.real, z.imaginary);
        
        if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->escape_value)
        {
            // color = scale(i, BLACK, WHITE, 0, fractal->iterations);
            // color = ((0xE6E6FA - 0x191970) / fractal->iterations) * i;
            color = mypalette3[39 - (int)scale(i, 0, 39, 0, fractal->iterations)];
            my_mlx_pixel_put(&fractal->img, x, y, color);
            return ;
        }
        i++;
    }
    
    // my_mlx_pixel_put(&fractal->img, x, y, 0x00EDF5);
    // my_mlx_pixel_put(&fractal->img, x, y, mystic_midnight_compl);
    my_mlx_pixel_put(&fractal->img, x, y, mypalette3_compl);
    


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
    // free(fractal->mlx_connection);
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
        // printf("error\n");
}

int main (int arcc, char **arcv)
{
    // void        *mlx;
    // void        *mlx_window;
    t_fractal   fractal;
    // t_img       img;

    fractal.name = arcv[1];
    fractal.escape_value = 4;
    fractal.iterations = 42;
    fractal.shift_x = 0.0;
    fractal.shift_y = 0.0;
    fractal.zoom = 1.0;
    fractal.range = 4.0;
    printf("fractal name : %s\n", fractal.name);
    if ((arcc == 2 && !ft_strncmp(arcv[1], "mandelbrot", 10)) 
    || (arcc == 2 && !ft_strncmp(arcv[1], "burning_ship", 12))
    || (arcc == 2 && !ft_strncmp(arcv[1], "phoenix", 7))
    || (arcc == 4 && !ft_strncmp(arcv[1], "julia", 5)))
    {
        if (arcc == 4)
        {
            fractal.julia_x = (ft_atod(arcv[2]));
            printf("julia real : %f\n", fractal.julia_x);
            fractal.julia_y = (ft_atod(arcv[3]));
            printf("julia imaginary : %f\n", fractal.julia_y);
        }

        fractal_init(&fractal);
        

        fractal_render(&fractal);


        // CORRECT PROMPT
        // printf("correct prompt");
        
        // mlx = mlx_init();
        // mlx_window = mlx_new_window(mlx, 1920, 1080, "My Window");

        // img.img = mlx_new_image(mlx, 1920, 1080);

        
        // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);


        // int x = 1160;
        // int y = 540;
        // double angle = 0.0;
        // int x_center = 960;
        // int y_center = 540;

        

        // while(angle < 360.0)
        // {
        //     my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
        //     mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
        //     angle += 0.5;
        //     x = x_center + (cos(angle * M_PI / 180) * 100);
        //     y = y_center + (sin(angle * M_PI / 180) * 100);
        // }

        // x = 1140;
        // y = 540;
        // angle = 0.0;

        // while(angle < 360.0)
        // {
        //     my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
        //     mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
        //     angle += 0.5;
        //     x = x_center + (cos(angle * M_PI / 180) * 80);
        //     y = y_center + (sin(angle * M_PI / 180) * 80);
        // }


        event_init(&fractal);

        mlx_loop(fractal.mlx_connection);

    // system("leaks fractol");


    }
    else
    {
        //ERROR
        ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
        exit(EXIT_FAILURE);

    }
}