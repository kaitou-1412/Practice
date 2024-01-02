import { createSlice } from "@reduxjs/toolkit";

const cartSlice = createSlice({
  name: "cart",
  initialState: {},
  reducers: {
    increaseItemQuantity: (state, action) => {
      const id = action.payload.id;
      if (!state[id]) {
        state[id] = {
          item: action.payload,
          quantity: 0,
        };
      }
      state[id].quantity += 1;
    },
    decreaseItemQuantity: (state, action) => {
      const id = action.payload.id;
      if (state[id]) {
        state[id].quantity -= 1;
        if (state[id].quantity === 0) {
          delete state[id];
        }
      }
    },
    removeItem: (state, action) => {
      const id = action.payload.id;
      if (state[id]) {
        delete state[id];
      }
    },
    clearCart: (state) => {
      Object.keys(state).forEach((id) => {
        delete state[id];
      });
    },
  },
});

export const {
  increaseItemQuantity,
  decreaseItemQuantity,
  removeItem,
  clearCart,
} = cartSlice.actions;

export default cartSlice.reducer;
