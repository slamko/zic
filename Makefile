CC=gcc

install:
	mkdir -p /usr/include/
	cp -r ./lib/zic /usr/include/
	mkdir -p /usr/share/doc/zic/
	cp ./README.md /usr/share/doc/zic/
	mkdir -p /usr/share/man/man1/
	cp ./zic.1 /usr/share/man/man1/ 

uninstall:
	$(RM) -r /usr/include/zic/
	$(RM) -r /usr/share/doc/zic/
	$(RM) /usr/share/man/man1/zic.1
