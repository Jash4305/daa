class Movie extends Thread {

    int v = 2, r;
  
    Movie(int x) {
      r = x;
    }
  
    public synchronized void run() {
      System.out.println("Available Ticket : "+v);
      if (r <= v) {
        System.out.println(
          "tickets are booked for " + Thread.currentThread().getName()
        );
        try {
          Thread.sleep(100);
        } catch (Exception e) {}
        v = v - r;
      } else {
        System.out.println("Housefull " + Thread.currentThread().getName());
      }
    }
  }
  
  class MultiThread {
  
    public static void main(String z[]) {
      Movie m = new Movie(1);
      Thread t1 = new Thread(m);
      Thread t2 = new Thread(m);
      Thread t3 = new Thread(m);
      Thread t4 = new Thread(m);
      t1.setName("Thread 1 ");
      t2.setName("Thread 2");
      t3.setName("Thread 3");
      t4.setName("Thread 4");
      t1.start();
      t2.start();
      t3.start();
      t4.start();
    }
  }
