#ifndef UREM_DMDocPerCFH                  
#define UREM_DMDocPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocPerCF();                                                           
   ~TREM_DMDocPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
