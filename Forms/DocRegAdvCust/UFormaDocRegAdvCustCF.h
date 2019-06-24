#ifndef UFormaDocRegAdvCustCFH                  
#define UFormaDocRegAdvCustCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocRegAdvCustCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocRegAdvCustCF();                                                           
   ~TFormaDocRegAdvCustCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
