BUILD = build/libraries/

.PHONY: clean

main:
	$(MAKE) -C wizard-basic-0-compiler
	$(MAKE) -C wizard-basic-0-runtime

clean:
	$(MAKE) -C wizard-basic-0-compiler clean
	$(MAKE) -C wizard-basic-0-runtime clean
