

int _main(void) {

    extern void(*_CTOR_LIST)();

    void (**constructor)() = &_CTOR_LIST__;

    return 0;

}
