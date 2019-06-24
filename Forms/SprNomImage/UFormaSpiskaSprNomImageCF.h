#ifndef UFormaSpiskaSprNomImageCFH                  
#define UFormaSpiskaSprNomImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprNomImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprNomImageCF();                                                           
   ~TFormaSpiskaSprNomImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
