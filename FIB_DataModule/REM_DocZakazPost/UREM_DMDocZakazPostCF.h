#ifndef UREM_DMDocZakazPostCFH                  
#define UREM_DMDocZakazPostCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZakazPostCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZakazPostCF();                                                           
   ~TREM_DMDocZakazPostCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
