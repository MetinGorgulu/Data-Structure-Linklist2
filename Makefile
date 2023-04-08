baslat: cpp_derle o_bagla calistir

cpp_derle:

	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AgacDugum.cpp -o ./lib/AgacDugum.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -c -I "./include" ./src/Islemler.cpp -o ./lib/Islemler.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/KuyrukDugum.cpp -o ./lib/KuyrukDugum.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o

o_bagla:
	g++ ./lib/main.o ./lib/AgacDugum.o ./lib/Doku.o ./lib/Hucre.o ./lib/IkiliAramaAgaci.o ./lib/Islemler.o ./lib/Kuyruk.o ./lib/KuyrukDugum.o ./lib/Organ.o ./lib/Organizma.o ./lib/Radix.o ./lib/Sistem.o -o ./bin/program

calistir:
	./bin/program