import java.util.concurrent.Semaphore;

public class DiningPhilosophers {
    private static final int NUM_PHILOSOPHERS = 5;
    private static final Semaphore[] forks = new Semaphore[NUM_PHILOSOPHERS];
    private static final Semaphore mutex = new Semaphore(1);

    public static void main(String[] args) {
        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            forks[i] = new Semaphore(1);
        }

        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            Thread philosopher = new Thread(new Philosopher(i));
            philosopher.start();
        }
    }

    static class Philosopher implements Runnable {
        private final int id;

        public Philosopher(int id) {
            this.id = id;
        }

        private void think() throws InterruptedException {
            System.out.println("Philosopher " + id + " is thinking");
            Thread.sleep(1000); // Simulate thinking time
        }

        private void eat() throws InterruptedException {
            mutex.acquire();
            forks[id].acquire(); // Acquire left fork
            forks[(id + 1) % NUM_PHILOSOPHERS].acquire(); // Acquire right fork
            mutex.release();

            System.out.println("Philosopher " + id + " is eating");
            Thread.sleep(1000); // Simulate eating time

            forks[id].release(); // Release left fork
            forks[(id + 1) % NUM_PHILOSOPHERS].release(); // Release right fork
        }

        @Override
        public void run() {
            try {
                while (true) {
                    think();
                    eat();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}