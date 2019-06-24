#ifndef UFormaSpiskaObjectBasePrivCFH                  
#define UFormaSpiskaObjectBasePrivCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaObjectBasePrivCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaObjectBasePrivCF();                                                           
   ~TFormaSpiskaObjectBasePrivCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
