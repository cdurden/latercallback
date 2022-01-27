#include <uv.h>
#include <unistd.h>

#include <Rcpp.h>
#include <later_api.h>
//https://cran.r-project.org/web/packages/later/vignettes/later-cpp.html
//https://mfasiolo.github.io/sc2-2019/rcpp/3_rcpp/

struct func_data {
    const Rcpp::Function func;
    //SEXP expr; // FIXME: Uncommenting this line prevents segfault
};

void run_callback(void *callback_data_ptr) {
    ((struct func_data *) callback_data_ptr)->func();
}


class Listen : public later::BackgroundTask {
  public:
    Listen(const char* _path, void *_callback_data_ptr) :
      path(_path),
      callback_data_ptr((struct func_data *) _callback_data_ptr)
    { }

  protected:
    void execute() {
        sleep(3);
    }

    void complete() {
      (new Listen(path, (void *) callback_data_ptr))->begin();
      later::later(run_callback, (void *) callback_data_ptr, 0);
    }

  private:
    const char* path;
    struct func_data *callback_data_ptr;
};


// [[Rcpp::export]]
void listenOn(const char* path, const Rcpp::Function callback) {
  PROTECT(callback); //FIXME: Removing this line leads to segfault
  struct func_data callback_data = { callback };
  (new Listen(path, (void *) &callback_data))->begin();
}
