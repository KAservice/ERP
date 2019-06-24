#ifndef UDMGurDocPrihNaklCFH                  
#define UDMGurDocPrihNaklCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurDocPrihNaklCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurDocPrihNaklCF();                                                           
   ~TDMGurDocPrihNaklCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
