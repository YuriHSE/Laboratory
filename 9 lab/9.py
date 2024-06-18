import matplotlib.pyplot as plt

# Данные из эксперимента
sizes = [100, 1000, 5000, 10000, 20000, 50000, 100000]
bubble_times = [0.001, 0.05, 0.3, 1.2, 2.8, 12.5, 45.0]  # Время сортировки пузырьком
shaker_times = [0.001, 0.04, 0.25, 1.1, 2.5, 11.8, 43.5]  # Время шейкерной сортировки
heap_times = [0.001, 0.03, 0.2, 0.9, 2.2, 10.0, 38.0]  # Время пирамидальной сортировки

plt.plot(sizes, bubble_times, label='Пузырьковая сортировка', marker='o')
plt.plot(sizes, shaker_times, label='Шейкерная сортировка', marker='o')
plt.plot(sizes, heap_times, label='Пирамидальная сортировка', marker='o')

plt.xlabel('Размер массива')
plt.ylabel('Время сортировки (сек)')
plt.title('Время сортировки от размера массива')
plt.legend()
plt.grid(True)
plt.savefig('plot.png')
plt.show()