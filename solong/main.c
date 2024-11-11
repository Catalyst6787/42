#include "./mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data {
    void    *img;
    void    *nimg;
    char    *addr;
    char    *naddr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     first_dots_shown;
}               t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); // calculate offset in winlen
    *(unsigned int*)dst = color;
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    if (!mlx_win)
        return (free(mlx), 1);

    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    img.first_dots_shown = 0;  // initialize to false

    // Initial dots
    my_mlx_pixel_put(&img, 5, 5, 0xf9f9f9);
    my_mlx_pixel_put(&img, 5, 7, 0xf9f9f9);
    my_mlx_pixel_put(&img, 5, 9, 0xf9f9f9);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    // Start the event loop with the update function
    //mlx_loop_hook(mlx, update_screen, &img);

    mlx_loop(mlx);
    
    mlx_destroy_window(mlx, mlx_win);
    free(mlx);
    return 0;
}