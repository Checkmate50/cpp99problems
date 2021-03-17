targets = 1 2 3 4 5 6 7 8 9 10

define make-target
	$1:
		g++ -std=c++17 $1.cpp -o $1.exe
		.\$1.exe
endef

$(foreach element,$(LIST),$(eval $(call make-target,$(element))))

clean:
	rm *.exe