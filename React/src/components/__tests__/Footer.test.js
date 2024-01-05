import { render } from "@testing-library/react";
import Footer from "../Footer";

test("footer text should load on rendering Footer", () => {
  // Load Footer Component
  const footer = render(<Footer />);

  // check if footer text is loaded
  const footerText = footer.getByTestId("footer").innerHTML;
  expect(footerText).toBe(
    "This site is developed by Dummy Name - dummy@gmail.com"
  );
});
