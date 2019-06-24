#ifndef UObjectBarCodeCFH                  
#define UObjectBarCodeCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TObjectBarCodeCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TObjectBarCodeCF();                                                           
   ~TObjectBarCodeCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
