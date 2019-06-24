#ifndef UFormaSpiskaTableExtPrintFormCFH                  
#define UFormaSpiskaTableExtPrintFormCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaTableExtPrintFormCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaTableExtPrintFormCF();                                                           
   ~TFormaSpiskaTableExtPrintFormCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
