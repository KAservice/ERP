#ifndef UDMTableExtPrintFormCFH                  
#define UDMTableExtPrintFormCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMTableExtPrintFormCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMTableExtPrintFormCF();                                                           
   ~TDMTableExtPrintFormCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
