#ifndef UREM_DMDocRemontCFH                  
#define UREM_DMDocRemontCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocRemontCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocRemontCF();                                                           
   ~TREM_DMDocRemontCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
