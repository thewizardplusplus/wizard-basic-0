BUILD = build/libraries/

.PHONY: clean

main:
	$(MAKE) -C wizard-basic-4-compiler
	$(MAKE) -C wizard-basic-4-runtime

clean:
	$(MAKE) -C wizard-basic-4-compiler clean
	$(MAKE) -C wizard-basic-4-runtime clean
