#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *philospher(int num);
pthread_t thr[5];
pthread_mutex_t chStick[5];

int main()
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_init(&chStick[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&thr[i], NULL, (void *)philospher, (void *)(intptr_t)i);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(thr[i], NULL);
    }
}

void *philospher(int num)
{
    printf("philosopher %d is thinking !!\n", num + 1);
    pthread_mutex_lock(&chStick[num]);
    pthread_mutex_lock(&chStick[(num + 1) % 5]);
    printf("philosopher %d is eating using chopstick[%d] and chopstick[%d]!!\n", num + 1, num, (num + 1) % 5);
    sleep(1);
    pthread_mutex_unlock(&chStick[num]);
    pthread_mutex_unlock(&chStick[(num + 1) % 5]);
    printf("philosopher %d finished eating !!\n", num + 1);
}