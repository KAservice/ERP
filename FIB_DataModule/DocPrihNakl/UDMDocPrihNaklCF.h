#ifndef UDMDocPrihNaklCFH                  
#define UDMDocPrihNaklCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocPrihNaklCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocPrihNaklCF();                                                           
   ~TDMDocPrihNaklCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
