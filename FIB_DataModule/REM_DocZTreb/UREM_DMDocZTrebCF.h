#ifndef UREM_DMDocZTrebCFH                  
#define UREM_DMDocZTrebCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocZTrebCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocZTrebCF();                                                           
   ~TREM_DMDocZTrebCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
