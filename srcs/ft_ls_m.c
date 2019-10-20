#include "../includes/ft_ls_m.h"

int	main(int ac, char **av)
{
	t_fileinfo  file;
	//init_ls();//clean structs

	if((g_file_count = parse_input(ac, av)) == 0)
	{
		get_fileinfo(&file, ".", ".");
		ft_mlstpush(&g_args, ft_mlstnew(&file, sizeof(t_fileinfo)));
		//ft_vecadd(g_args, &file);
	}
	printf("before:\n");
	printList(g_args);
	ls_sort_args();
	printf("\nafter:\n");
	printList(g_args);


	/*	printf("before_sort:\n");
	for (int i = 0; i < g_args->count; i++)
	{
		printf("data[%d] = %s\n", i, ((t_fileinfo*)(g_args->data)[i])->name);
	}
	ls_sort_args();
	printf("ater_sort:\n");
	for (int i = 0; i < g_args->count; i++)
	{
		printf("data[%d] = %s\n", i, ((t_fileinfo*)(g_args->data)[i])->name);
	}*/


   // while (g_args)
        //grand_loop();

        /*DIR				*dir;
    struct dirent	*f_d;
    t_vector		*v;
    t_test			*tst;
    struct	ft_stat	ft_stat;

    int ch;
    t_flgs          flgs;
    //ls_parse_input()


    //v = ft_vecnew();
    dir = opendir(argv[1]);
    while ((f_d = readdir(dir)))
    {
        tst = (t_test *)malloc(sizeof(t_test ));
        printf ("{%s}\n",f_d->d_name);
        ft_stat(ft_strjoin(argv[1], f_d->d_name), &(tst->ft_stat));//tmp - delete

        tst->name = f_d->d_name;
       // printf ("size[%s] = {%lld}\n ", tst->name,tst->ft_stat.st_blocks);
        ft_vecadd(v, tst);
    }

    char *sort_flg = "rat";
    int ifun = cmpfun_indx(&flgs);

    quicksort(v, 0, v->count - 1, &flgs);

    printf("ater_sort:\n");
    for (int i = 0; i < v->count; i++)
    {
        printf("data[%d] = %s\n", i, ((t_test*)(v->data)[i])->name);
    }-*/
}

