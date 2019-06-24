#ifndef UREM_DMDocPrihNaklCFH                  
#define UREM_DMDocPrihNaklCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocPrihNaklCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocPrihNaklCF();                                                           
   ~TREM_DMDocPrihNaklCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
