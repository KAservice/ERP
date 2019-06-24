#ifndef UFormaDocPrihNaklCFH                  
#define UFormaDocPrihNaklCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocPrihNaklCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocPrihNaklCF();                                                           
   ~TFormaDocPrihNaklCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
