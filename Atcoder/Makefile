run:
	./sol < in.txt

a:
	g++ -o sol a.cc

rba: a run

	
b:
	g++ -o sol b.cc

rb:
	./sol < in.txt

rbb: b rb

c:
	g++ -o sol c.cc

rc:
	./sol < in.txt

rbc: c rc


m:
	g++ -o sol main.cc

rbm: m run
