/*falta el header*/

int ft_die(t_philos *philos)
{

}

int ft_mealcounter(t_philos *philos, t_data *data)
{
    
}

void ft_monitor(t_data *data, t_philos *philos)
{
    int i;

    i = 0;
    while (1)
    {
        if (i == data->n_philos)
            i = 0;
        if (ft_die(&philos[i]) || ft_mealcounter(philos, data))
        {
            phtread_mutex_lock(&philos->data->write_lock);
            data->dead_flag = 1;
            break ;
        }
        usleep(1000);
        i++;
    }
    phtread_mutex_unlock(&philos->data->write_lock);
}