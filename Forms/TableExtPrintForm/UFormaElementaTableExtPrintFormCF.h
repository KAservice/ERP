#ifndef UFormaElementaTableExtPrintFormCFH                  
#define UFormaElementaTableExtPrintFormCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaTableExtPrintFormCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaTableExtPrintFormCF();                                                           
   ~TFormaElementaTableExtPrintFormCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
