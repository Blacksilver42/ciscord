# Conventions 

* Functions starting with`D_`, AKA "the D series" **Do actual API calls**
* Functions starting with `ld_`, AKA "not the D series" **Don't do any API calls**
* Initializer functions take the form `ld_*_make(buf)`
    * There is often a `ld_*_alloc(buf)` helper function; __DON'T USE IT__
