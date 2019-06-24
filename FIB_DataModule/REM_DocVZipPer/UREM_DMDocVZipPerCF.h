#ifndef UREM_DMDocVZipPerCFH                  
#define UREM_DMDocVZipPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocVZipPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocVZipPerCF();                                                           
   ~TREM_DMDocVZipPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
