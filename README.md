# Ford-Fulkerson-algorithm
Ford-Fulkerson algoritması, bir akış ağındaki maksimum akışı bulmak için kullanılan bir algoritmadır. Algoritma, artan bir yol bulmak için artan yol problemini çözer. Başlangıçta maksimum akış sıfırdır ve her adımda artan bir yol bulunarak maksimum akış artırılır. Artan yol bulmak için genellikle genişlik öncelikli arama veya derinlik öncelikli arama kullanılır.

Algoritmanın zaman karmaşıklığı, artan yolu bulmak için kullanılan arama algoritmasına bağlıdır. En kötü durumda, algoritmanın zaman karmaşıklığı O(Ef), burada E ağdaki kenar sayısı ve f maksimum akıştır. Ancak, algoritma genellikle daha hızlı çalışır ve pratikte en iyi yaklaşık O(E^2 f) zaman karmaşıklığına sahiptir.

Asimptotik analiz, bir algoritmanın en iyi, en kötü ve ortalama durum zaman sınırlarını belirlemeye yardımcı olan bir tekniktir. Ford-Fulkerson algoritması için, en kötü durum zaman karmaşıklığı O(Ef) veya O(E^2 f) olabilir, ancak algoritmanın gerçek çalışma zamanı, ağdaki kenar sayısı ve maksimum akış miktarına bağlı olarak değişebilir.

Bu algoritmanın matematiksel analizi, artan yolların nasıl bulunacağı, maksimum akışın ne zaman bulunacağı ve algoritmanın her adımında maksimum akışın nasıl artırılacağı gibi konuları kapsar. Algoritmanın daha ayrıntılı bir matematiksel analizi, özellikle belirli bir örnekteki akış ağına bağlı olarak değişebilir.
